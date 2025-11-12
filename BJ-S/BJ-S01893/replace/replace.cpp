#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e6+7;
int n,q;
map<string,int> m;
int main() {
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++) {
        string s1,s2;
        cin>>s1>>s2;
        int l,r=-1;
        int len1=s1.size(),len2=s2.size();
        if(len1!=len2) {
            cout<<0<<"\n";
            continue;
        }
        int flag=0;
        for(int i=0;i<len1;i++) {
            if(s1[i]!=s2[i]&&!flag) {
                l=i;
                flag=1;
            }
            else if(s1[i]!=s2[i]&&flag==1) {
              //      cout<<"i:: "<<i<<"\n";
                r=i;
                flag=2;
            }
            else if(s1[i]!=s2[i]&&flag==2) {
              //      cout<<"i:: "<<i<<"\n";
                r=i;
            }
        }
        if(r==-1&&len1>1) r=l+1;
        else if(r==-1) r=l;
    //    cout<<"l:: "<<" r:: "<<r<<"\n";
        string sa,sb;
        for(int i=l;i<=r;i++) {
            sa+=s1[i];
        }
        for(int i=l;i<=r;i++) {
            sb+=s2[i];
        }
        string ke=sa+sb;
        m[ke]++;
    }
    while(q--) {
        string s1,s2;
        cin>>s1>>s2;
        int l,r;
        int len1=s1.size(),len2=s2.size();
        if(len1!=len2) {
            cout<<0<<"\n";
            continue;
        }
        int flag=0;
        for(int i=0;i<len1;i++) {
            if(s1[i]!=s2[i]&&!flag) {
                l=i;
                flag=1;
            }
            else if(s1[i]!=s2[i]&&flag==1) {
              //      cout<<"i:: "<<i<<"\n";
                r=i;
                flag=2;
            }
            else if(s1[i]!=s2[i]&&flag==2) {
              //      cout<<"i:: "<<i<<"\n";
                r=i;
            }
        }
        if(r==-1&&len1>1) r=l+1;
        else if(r==-1) r=l;
        string sa,sb;
        for(int i=l;i<=r;i++) {
            sa+=s1[i];
        }
        for(int i=l;i<=r;i++) {
            sb+=s2[i];
        }
        string ke=sa+sb;
        cout<<m[ke]<<"\n";
    }
    return 0;
}
