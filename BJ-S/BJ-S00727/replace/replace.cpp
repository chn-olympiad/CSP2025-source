#include<bits/stdc++.h>
using namespace std;

const int N=5e6+5;

unordered_map<string,int> mp1;

string mp2[N];

struct node {
    int qian,hou;
} si1[N],si2[N] ;

int main() {
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    int n,q;
    cin>>n>>q;

    if(n<=100||q==1||(n<=1000&&q!=1)) {
        
        for(int i=1;i<=n;i++) {
            string s1,s2;
            cin>>s1>>s2;
            mp1[s1]=i;
            mp2[i]=s2;
        }

        while(q--) {
            string t1,t2;
            cin>>t1>>t2;
            t1=" "+t1;
            t2=" "+t2;
            int ans=0;
            for(int i=1;i<t1.size();i++) 
                for(int j=i;j<t1.size();j++) {
                    string x,y,z;
                    for(int k=1;k<i;k++)                x+=t1[k];
                    for(int k=i;k<=j;k++)               y+=t1[k];
                    for(int k=j+1;k<t1.size();k++)      z+=t1[k];
                    // cout<<i<<" "<<j<<endl;
                    // cout<<"["<<x<<"] ["<<y<<"] ["<<z<<"] "<<x+mp2[mp1[y]]+z<<" "<<(mp1[y]!=0&&" "+x+mp2[mp1[y]]+z==t2)<<endl;
                    if(mp1[y]!=0&&" "+x+mp2[mp1[y]]+z==t2)  ans++;
                }
            cout<<ans<<endl;
        }
    }

    else {
        for(int i=1;i<=n;i++) {
            string s1,s2;
            cin>>s1>>s2;
            for(int j=0;j<s1.size();j++)    
                if(s1[j]=='b')  {
                    si1[i].qian=j;
                    si1[i].hou=s1.size()-1-j;
                    break;
                }
            for(int j=0;j<s2.size();j++)    
                if(s2[j]=='b')  {
                    si2[i].qian=j;
                    si2[i].hou=s2.size()-1-j;
                    break;
                }
        }
        

        while(q--) {
            string t1,t2;
            cin>>t1>>t2;
            node ti1,ti2;
            for(int j=0;j<t1.size();j++)    
                if(t1[j]=='b')  {
                    ti1.qian=j;
                    ti1.hou=t1.size()-1-j;
                    break;
                }
            for(int j=0;j<t2.size();j++)    
                if(t2[j]=='b')  {
                    ti2.qian=j;
                    ti2.hou=t2.size()-1-j;
                    break;
                }
            int ans=0;
            for(int i=1;i<=n;i++) {
                if(si1[i].qian<=ti1.qian&&si1[i].hou<=ti1.hou) {
                    node newt=ti1;
                    newt.qian-=si1[i].qian;
                    newt.hou-=si1[i].hou;
                    newt.qian+=si2[i].qian;
                    newt.hou+=si2[i].hou;
                    if(newt.qian==ti2.qian && newt.hou==ti2.hou) {
                        ans++;
                    }
                }
            }
            cout<<ans<<endl;
        }
    }

    return 0;
}
