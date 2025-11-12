#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s1[N],s2[N];
bool vis[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    string t1,t2;
    while(q--){
        memset(vis,0,sizeof(vis));
        cin>>t1>>t2;
        int a=-1,b;
        for(int i=0;i<t1.size();i++){
            if(t1[i]!=t2[i]){
                if(a==-1)a=i;
                b=i;
            }
        }
        int ans=0;
        for(int i=0;i<=a;i++){
            for(int j=1;j<=n;j++){
                if(s1[j].size()<a-i+b-a+1||i+s1[j].size()>t1.size()||vis[j]) continue;
                //cout<<i<<" "<<j<<endl;
                int T=1;
                for(int k=i;k<=i+s1[j].size()-1;k++){
                    if(t1[k]!=s1[j][k-i]||s2[j][k-i]!=t2[k]){
                        T=0;
                        break;
                    }
                }
                if(T){
                    ans++;
                    vis[j]=1;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
