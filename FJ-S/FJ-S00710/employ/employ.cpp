#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
struct node{
	int num,bh;
}a[1010];
int n,m,ot[1010],b[1010],maxa;
char c[1010];
long long ans,pl[1010],sum=1,ss;

void init()
{
	pl[1]=1; pl[0]=1;
	for(int i=2;i<=n;i++)
	 {
	 	pl[i]=i*pl[i-1];
	 	pl[i]%=M;
	 }
}

bool cmp(node x,node y)
{
	return x.num<y.num;
}

void dfs(int s,int y,int x)
{
	if(n-y+1-ot[n]+ot[y-1]<m-s) return ;
	if(y>n)
	 {
	 	if(s>=m) ans+=sum;
	 	ans%=M;
	 	return ;
	 }
	if(c[y]=='0')
	 {
	 	for(int i=0;i<=maxa;i++)
	 	 {
	 	 	if(b[i])
	 	 	 {
	 	 	 	b[i]--;
	 	 	 	dfs(s,y+1,x+1);
	 	 	 	b[i]++;
			   }
		  }
	 	
	 }
	else
	 {
	 	for(int i=0;i<=maxa;i++)
	 	 {
	 	 	if(b[i])
	 	 	 {
	 	 	 	if(i>x)
	 	 	 	{
	 	 	 		b[i]--;
	 	 	 		dfs(s+1,y+1,x);
	 	 	 		b[i]++;
				   }
				else
				 {
				 	b[i]--;
				 	dfs(s,y+1,x+1);
				 	b[i]++;
				 }
			   }
		  }
	 }
}

/*void dfs1(int s,int y,int x)
{
	if(y>n)
	 {
	 	ans+=sum;
	 	ans%=M;
	 	return;
	 }
	if(c[y]=='0')
	 {
	 	for(int i=maxa;i>=0;i++)
	 	 {
	 	 	if(b[i])
	 	 	 {
	 	 	 	b[i]--;
	 	 	 	dfs(s,y+1,x+1);
	 	 	 	b[i]++;
			   }
		  }
	 	return;
	 }
	for(int i=x;i>=0;i++)
	 {
	 	if(i>x) continue;
	 	if(b[i])
	 	  {
	 		b[i]--;
	 	 	dfs(s,y+1,x+1);
	 	 	b[i]++;
		   }
	 }
}*/

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	init();
	for(int i=1;i<=n;i++)
	 {
	 	cin>>c[i];
	 	if(c[i]=='1') ss++;
	 }
	for(int i=1;i<=n;i++)
	 {
	 	cin>>a[i].num;
	 	a[i].bh=i;
	 	maxa=max(a[i].num,maxa);
	 	b[a[i].num]++;
	 }
	for(int i=0;i<=maxa;i++)
	 {
	 	sum*=pl[b[i]];
	 	sum%=M;
	 }
	if(m==n)
	 {
	 	if(b[0]) cout<<0;
	 	else
	 	 {
	 	 	cout<<sum;
		  }
		exit(0);
	 }
	/*if(m==1)
	 {
	 	dfs1(0,1,0);
	 	ans=pl[n]-ans;
	 	if(ans<0) ans+=M;
	 	cout<<ans;
	 	exit(0);
	 }*/
	if(ss==n)
	 {
	 	if(n-b[0]>=m)
	 	 {
	 	 	int j=1;
	 	 	ss=b[0];
	 	 	ans=pl[n-ss]*pl[ss]%M;
	 	 	for(int i=1;i<=b[0];i++)
	 	 	 {
	 	 	 	while(b[j]==0) j++;
	 	 	 	ss+=b[j]; j++;
	 	 	 	if(n-ss<m) break;
	 	 	 	ans+=(pl[n-ss]*pl[ss-i]%M)*pl[b[0]]%M;
			   }
		  }
		cout<<ans;
	 	exit(0);
	 }
	sort(a+1,a+n+1,cmp);
	dfs(0,1,0);
	cout<<ans;
	return 0;
}
