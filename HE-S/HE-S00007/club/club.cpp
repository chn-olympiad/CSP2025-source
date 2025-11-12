#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int t,n,s[4],ans,ans1,k;
bool A,B;
struct node{
	int a,b,c,maxn;
}a[N];
bool cmp(node a,node b){
	return a.maxn>b.maxn;
}
bool cmp1(node a,node b){
	return abs(a.a-a.b)>abs(b.a-b.b);
}
void dfs(int x,int sum)
{
	ans=max(ans,sum);
	if(x>n) return;
	for(int i=x;i<=n;i++)
	{
		if(s[1]<k){
			s[1]++;
			dfs(i+1,sum+a[i].a);
			s[1]--;
		}
		if(s[2]<k){
			s[2]++;
			dfs(i+1,sum+a[i].b);
			s[2]--;
		}
		if(s[3]<k){
			s[3]++;
			dfs(i+1,sum+a[i].c);
			s[3]--;
		}
	}
}
void solve()
{
	cin>>n;
	k=n/2,ans=ans1=0,A=B=0;
	for(int i=1;i<=3;i++) s[i]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].a>>a[i].b>>a[i].c;
		if(a[i].b!=0||a[i].c!=0) A=1;
		if(a[i].c!=0) B=1;
		a[i].maxn=max(a[i].a,max(a[i].b,a[i].c));
	}
	if(n<=20){
		dfs(1,0);
		cout<<ans<<'\n';
		return;
	}
	if(B==0)
	{
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;i++)
		{
			if(a[i].a>a[i].b&&s[1]<n/2) ans1+=a[i].a,s[1]++;
			else ans1+=a[i].b,s[2]++;
		}
	}
	sort(a+1,a+n+1,cmp);
	if(A==0)
	{
		for(int i=1;i<=n/2;i++) ans+=a[i].a;
		cout<<ans<<'\n';
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if((a[i].a>=max(a[i].b,a[i].c)&&s[1]<k)||(a[i].a>a[i].c&&s[2]==k)) ans+=a[i].a,s[1]++;
		else if((a[i].b>=max(a[i].a,a[i].c)&&s[2]<k)||(a[i].b>a[i].c&&s[2]<k&&s[1]==k)||(s[3]==k)) ans+=a[i].b,s[2]++;
		else ans+=a[i].c,s[3]++;
	}
	cout<<max(ans,ans1)<<'\n';
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(nullptr) -> ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
