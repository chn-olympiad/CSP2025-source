#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
struct node{
	int id;
	int x,y,z;
	int o,p,q;
}a[N];
bool cmp(node u,node v)
{
	if(u.x==v.x)
	{
		if(u.y==v.y)
		{
			return u.z>v.z;
		}
		return u.y>v.y;
	}
	return u.x>v.x;
}
int cnt[5];
void solve()
{
	for(int i=1;i<=n;i++)
	{
		a[i].o=1,a[i].p=2,a[i].q=3;
		if(a[i].x<a[i].y)
		{
			swap(a[i].x,a[i].y);
			swap(a[i].o,a[i].p);
			if(a[i].x<a[i].z)
			{
				swap(a[i].x,a[i].z);
				swap(a[i].o,a[i].q);
			} 
			if(a[i].y<a[i].z)
			{
				swap(a[i].y,a[i].z);
				swap(a[i].p,a[i].q);
			} 
		} 
		else
		{
			if(a[i].x<a[i].z)
			{
				swap(a[i].x,a[i].z);
				swap(a[i].o,a[i].q);
			} 
			if(a[i].y<a[i].z)
			{
				swap(a[i].y,a[i].z);
				swap(a[i].p,a[i].q);
			} 
		}
		//cout<<a[i].o<<" "<<a[i].p<<" "<<a[i].q<<endl;
		a[i].id=i;
	}
	sort(a+1,a+1+n,cmp);
	
	//for(int i=1;i<=n;i++) cout<<a[i].o<<" "<<a[i].p<<" "<<a[i].q<<endl;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		//cout<<a[i].id<<":";
		bool flag=0;
		for(int j=1;j<=3;j++)
		{
			if(j==1)
			{
				if(cnt[a[i].o]+1<=n/2)
				{
					flag=1;
					cnt[a[i].o]++;
					ans+=a[i].x;
					//cout<<a[i].o<<endl;
				}
			}
			else if(j==2)
			{
				if(cnt[a[i].p]+1<=n/2)
				{
					flag=1;
					cnt[a[i].p]++;
					ans+=a[i].y;
					//cout<<a[i].p<<endl;
				}
			}
			else if(j==3)
			{
				if(cnt[a[i].q]+1<=n/2)
				{
					flag=1;
					cnt[a[i].q]++;
					ans+=a[i].z;
					//cout<<a[i].q<<endl;
				}
			}
			if(flag==1) break;
		 } 
	}
	printf("%lld\n",ans);
	return;
}
int ord[N];
long long res=0;
void dfs(int x)
{
	for(int i=1;i<=3;i++)
	{
		if(cnt[i]>n/2) return;
	}
	if(x>n)
	{
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			//cout<<ord[i]<<" ";
			if(ord[i]==1) ans+=a[i].x;
			else if(ord[i]==2) ans+=a[i].y;
			else if(ord[i]==3) ans+=a[i].z;
		}
		//cout<<ans<<endl;
		res=max(res,ans);
		return;
	}
	if(cnt[1]+1<=n/2)
	{
		ord[x]=1,cnt[1]++;
		dfs(x+1);
		cnt[1]--;
	} 
	
	
	if(cnt[2]+1<=n/2)
	{
		ord[x]=2,cnt[2]++;
		dfs(x+1);
		cnt[2]--;
	} 
	

	if(cnt[3]+1<=n/2)
	{
		ord[x]=3,cnt[3]++;
		dfs(x+1);
		cnt[3]--;
	} 
	
}
bool check1()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i].y!=0||a[i].z!=0) return false;
	}
	return true;
}
void solve2()
{
	memset(ord,0,sizeof(ord));
	dfs(1);
	printf("%lld\n",res);
}
void solveA()
{
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n/2;i++)
	{
		res+=a[i].x;
	}
	cout<<res<<endl;
	return;
}
bool check2()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i].z!=0) return false;
	}
	return true;
}
void solveB()
{
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=a[i].x+a[i].y;
	}
	cout<<ans<<endl;
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		cin>>n;
		res=0;
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++) a[i].x=a[i].y=a[i].z=a[i].id=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].z);
			//cout<<a[i].o<<" "<<a[i].p<<" "<<a[i].q<<endl;
		}
		if(check1())
		{
			solveA();
		}
		else if(check2())
		{
			solveB();
		}
		else if(n<=10) solve2();
		else solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
