#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define db long double
#define F(i,k,n) for (int i=k;i<=n;i++)
#define R(i,k,n) for (int i=k;i>=n;i--)
#define ins insert
#define mpr make_pair
#define pu push_back
#define mes(a,b) memset(a,b,sizeof a);
const int N=2e5+10;
//2326968
int n,q;
string s[N][2];
string t1,t2;
int len[N];
bool k[N];
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    F(i,1,n){
        cin>>s[i][1]>>s[i][2];
        len[i]=(int)s[i][1].size();
        s[i][1]=" "+s[i][1];
        s[i][2]=" "+s[i][2];
    }
    F(i,1,q){
        cin>>t1>>t2;
        if ((int)t1.size()!=(int)t2.size()){
            cout<<0<<'\n';
            continue;
        }
        int m=(int)t1.size();
        t1=" "+t1;
        t2=" "+t2;
        int mn=n+1,mx=0;
        F(j,1,m){
            if (t1[j]!=t2[j]) k[j]=1,mx=max(mx,j),mn=min(mn,j); 
        }
        int ans=0;
        F(j,1,mn){
            F(k,1,n){
                if (len[k]+j-1<mx || len[k]+j-1>m) continue;
                bool flag=0;
                F(p,1,len[k]){
                    if (t1[p+j-1]!=s[k][1][p] || t2[p+j-1]!=s[k][2][p]){
                        flag=1;
                        break;
                    }
                }
                if (!flag) ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}