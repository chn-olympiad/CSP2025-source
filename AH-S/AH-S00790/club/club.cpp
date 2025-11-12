#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define vec vector<int>
#define pi pair<int,int>
void in(int &x){
	x=0;int f=1;char c=getchar();
	while((c>'9'||c<'0')&&c!='-')c=getchar();
	if(c=='-')f=-1,c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	x*=f;
}
int t,n,m,k,x,y,ans,b[5],c[100005];pi a[100005][5];
void solve(){
	in(n);int ans=0;memset(b,0,sizeof b);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++)in(a[i][j].first),a[i][j].second=j;
		sort(a[i]+1,a[i]+1+3);
	    ans+=a[i][3].first;b[a[i][3].second]++;
	}
	int mx=max({b[1],b[2],b[3]});
	if(mx<=n/2){printf("%d\n",ans);return;}
	int p=1;m=0;if(mx==b[2])p=2;if(mx==b[3])p=3;
	for(int i=1;i<=n;i++)if(a[i][3].second==p)c[++m]=a[i][3].first-a[i][2].first;
	sort(c+1,c+1+m);for(int i=1;i<=mx-n/2;i++)ans-=c[i];
    printf("%d\n",ans);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	in(t);
	while(t--)solve();
}