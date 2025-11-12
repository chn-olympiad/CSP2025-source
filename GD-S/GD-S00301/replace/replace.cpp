#include<bits/stdc++.h>
#define ll long long
#define fo(i,x,y) for(int i=(x);i<=(y);++i)
#define fu(i,x,y) for(int i=(x);i<(y);++i)
#define fd(i,x,y) for(int i=(x);i>=(y);--i)
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=2e5+5,M=5e6+6;
int n,q,ans,pi[M],pi2[M];
string s1[N],s2[N],S;
int main(){
    // freopen("replace3.in","r",stdin);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    fo(i,1,n){
        cin>>s1[i]>>s2[i];
        s1[i]="$"+s1[i];
        s2[i]="$"+s2[i];
    }
    while(q--){
        cin>>s1[0]>>s2[0];
        s1[0]="@"+s1[0];
        s2[0]="@"+s2[0];
        int ln=s1[0].size();
        int l,r;ans=0;
        fu(i,0,ln)if(s1[0][i]!=s2[0][i])r=i+1;
        fd(i,ln-1,0)if(s1[0][i]!=s2[0][i])l=i+1;
        fo(i,1,n){
            S=s1[i]+"#"+s1[0];
            int t=S.size(),t2=s1[i].size();
            fu(j,2,t){
                int k=pi[j-1];
                while(k&&S[k+1]!=S[j])k=pi[k];
                pi[j]=k+(S[k+1]==S[j]);
                // printf("%d ",pi[j]);
            }
            // puts("");
            S=s2[i]+"#"+s2[0];
            fu(j,2,t){
                int k=pi2[j-1];
                while(k&&S[k+1]!=S[j])k=pi2[k];
                pi2[j]=k+(S[k+1]==S[j]);
                // printf("%d ",pi[j]);
                if(pi2[j]==t2-1&&pi[j]==t2-1&&j-t2>=r&&j-t2-(t2-1)+1<=l)++ans;
            }
            // puts("");
        }
        printf("%d\n",ans);
    }
}