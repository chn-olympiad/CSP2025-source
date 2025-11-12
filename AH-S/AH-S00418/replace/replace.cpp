#include <iostream>
#include <cstdio>
#define MAXN 5000005
using namespace std;
int n,Q;
int l[MAXN],L;
string s1[MAXN],s2[MAXN];
string q1,q2;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>Q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        l[i]=s1[i].size();
    }
    while(Q--){
        cin>>q1>>q2;
        L=q1.size();
        int diff=0;
        for(int i=0;i<L;i++){
            if(q1[i]!=q2[i]){
                diff++;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(l[i]<diff) continue;
            int f=q1.find(s1[i]);
            while(f!=-1){
                string x,y,z;
                if(f-1>=0) x=q1.substr(0,f);
                y=s2[i];
                if(L-f-l[i]+1>=0) z=q1.substr(f+l[i],L-f-l[i]+1);
                //cout<<f<<endl;
                //cout<<x<<" "<<y<<" "<<z<<endl;
                if(x+y+z==q2) ans++;
                f=q1.find(s1[i],f+1);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
