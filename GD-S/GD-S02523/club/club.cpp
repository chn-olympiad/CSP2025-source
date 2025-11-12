#include<bits/stdc++.h>
#define ll long long
#define up(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e5+10;
ll _,n,A,B,C,ans,cnt[4],b[N],f[N],a[N][4];
struct node
{
	int x,id;
}c[N];
void work(int k)
{
	ll len=cnt[k],sum=0;
	up(i,1,n)
	{
		if(f[i]==k)
		{
			if(a[i][1]<a[i][2])swap(a[i][1],a[i][2]);
			if(a[i][1]<a[i][3])swap(a[i][1],a[i][3]);
			if(a[i][2]<a[i][3])swap(a[i][2],a[i][3]);
			c[++sum].x=a[i][1]-a[i][2];
			c[sum].id=i;
		}
	}
	sort(c+1,c+len+1,[](node a,node b){return a.x>b.x;});
	up(i,n/2+1,len)swap(a[c[i].id][1],a[c[i].id][2]);
	up(i,1,n)
	{
		if(f[i]==k)ans+=a[i][1];
		else ans+=a[i][f[i]];
	}
}
int main()
{
	freopen("club.in","r",stdin);	
	freopen("club.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>_;
	while(_--)
	{
		cin>>n;
		up(i,1,n)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])cnt[1]++,f[i]=1;
			if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])cnt[2]++,f[i]=2;
			if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2])cnt[3]++,f[i]=3;
		}
		if(cnt[1]>=cnt[2]&&cnt[1]>=cnt[3])work(1);
		if(cnt[2]>=cnt[1]&&cnt[2]>=cnt[3])work(2);
		if(cnt[3]>=cnt[2]&&cnt[3]>=cnt[1])work(3);
		cout<<ans<<'\n';
		ans=0;
		cnt[1]=cnt[2]=cnt[3]=0;
	}
	
	return 0;
} 
