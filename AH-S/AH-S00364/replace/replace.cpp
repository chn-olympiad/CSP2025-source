#include<bits/stdc++.h>
using namespace std;
int n,q;
map<string,string>m;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string s1,s2;
        cin>>s1>>s2;
        m[s1]=s2;
    }
    while(q--){
        string t1,t2;
        int ans=0,first=-1,last=-1;
        cin>>t1>>t2;
        for(int i=0;t1[i];i++){
            if(t1[i]!=t2[i]){
                if(first==-1)first=i;
                last=i;
            }
        }
        //cout<<first<<" "<<last<<endl;
        string p1,p2;
        for(int i=first;i<=last;i++){p1+=t1[i];p2+=t2[i];}
        for(int i=first;i>=0;i--){
            string c1=p1,c2=p2;
            p1=t1[i-1]+p1;p2=t2[i-1]+p2;
            for(int j=last;t1[j];j++){
                if(m[c1]==c2)ans++;
                c1+=t1[j+1];c2+=t2[j+1];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
