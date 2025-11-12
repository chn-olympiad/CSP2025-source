#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[35],b[35],c[35];
int ans=0;
void dfs(int u,int tot,int cnta,int cntb,int cntc){
    if(u>n){
        ans=max(ans,tot);
    }
    if(cnta<n/2)dfs(u+1,tot+a[u],cnta+1,cntb,cntc);
    if(cntb<n/2)dfs(u+1,tot+b[u],cnta,cntb+1,cntc);
    if(cntc<n/2)dfs(u+1,tot+c[u],cnta,cntb,cntc+1);
}
int main(){
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        bool f2=1;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            if(b[i]!=0)f2=0;
        }
        if(n<=15){
            dfs(1,0,0,0,0);
            cout<<ans<<"\n";
            ans=0;
            n=0;
            memset(a,0,sizeof a);
            memset(b,0,sizeof b);
            memset(c,0,sizeof c);
        }
        if(f2){
        	sort(a+1,a+n+1,greater<int>());
        	for(int i=1;i<=n/2;i++){
        		ans+=a[i];
			}
			cout<<ans<<"\n";
			ans=0;
            n=0;
            memset(a,0,sizeof a);
            memset(b,0,sizeof b);
            memset(c,0,sizeof c);
		}
    }
    return 0;
}