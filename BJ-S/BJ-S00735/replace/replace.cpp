#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
const int inf=1e8;
int n,q;
string rp[maxn][2];
bool pos[maxn];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>rp[i][0]>>rp[i][1];
    while(q--){
        string s1,s2;
        cin>>s1>>s2;
        int st=inf,ed=inf,l=s1.length();
        for(int i=0;i<=l;i++){
            if(s1[i]==s2[i])continue;
            else{
                if(st==inf)st=i;
                ed=i;
            }
        }
        int ans=0;
        for(int i=st;i<=ed;i++){
            for(int j=1;j<=n;j++){
                if(rp[j][0][i]!=s1[i] || rp[j][1][i]!=s2[i])pos[j]=false;
                else pos[j]=true;
            }
        }
        
        for(int i=0;i<=n;i++)
            if(pos[i])ans++;
        cout<<ans<<'\n';
    }
    return 0;
}
