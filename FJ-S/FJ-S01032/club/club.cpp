#include<bits/stdc++.h>
using namespace std;
const int N=1e5+20;
int n;
struct bin{
	int ma,x,y,z;
	bool val;
}a[N];
int b[N][4];
int t[4];
int dfs(int x)
{
	if(x>n) return 0;
	int ans=0;
	for(int i=1;i<=3;i++)
	{
		if(t[i]==n/2) continue;
		t[i]++;
		ans=max(ans,dfs(x+1)+b[x][i]);
		t[i]--;
	}
	return ans;
}
bool cmp1(bin x,bin y)
{
	return x.x>y.x;
}
bool cmp2(bin x,bin y)
{
	return x.y>y.y;
}
bool cmp3(bin x,bin y)
{
	return x.z>y.z;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int tt;
	cin>>tt;
	while(tt--)
	{
		int x,y,z;
		long long tot=0;
		scanf("%d",&n);
		if(n<=10)
		{
			t[1]=t[2]=t[3]=0;
			for(int i=1;i<=n;i++)
				scanf("%d%d%d",&b[i][1],&b[i][2],&b[i][3]);
			cout<<dfs(1)<<"\n";
		}
		else
		{
			t[1]=t[2]=t[3]=0;
			for(int i=1;i<=n;i++)
			{
				scanf("%d%d%d",&x,&y,&z);
				tot+=(x+y+z);
				a[i].x=x-y-z;
				a[i].y=y-x-z;
				a[i].z=z-y-x;
				a[i].val=0;
				a[i].ma=max(max(a[i].x,a[i].y),a[i].z);
				//cout<<"!!"<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<"\n";
			}
			long long ans=0;
			int k=0;
			sort(a+1,a+1+n,cmp1);
			for(int i=1;i<=n;i++)
			{
				if(t[1]==n/2) break;
				if(a[i].val) continue;
				if(a[i].ma==a[i].x) ans+=a[i].ma,a[i].val=1,t[1]++,k++;
			}
			sort(a+1,a+1+n,cmp2);
			for(int i=1;i<=n;i++)
			{
				if(t[2]==n/2) break;
				if(a[i].val) continue;
				if(a[i].ma==a[i].y) ans+=a[i].ma,a[i].val=1,t[2]++,k++;
			}
			sort(a+1,a+1+n,cmp3);
			for(int i=1;i<=n;i++)
			{
				if(t[3]==n/2) break;
				if(a[i].val) continue;
				if(a[i].ma==a[i].z) ans+=a[i].ma,a[i].val=1,t[3]++,k++;
			}
			if(k!=n)
			{
				for(int i=1;i<=n;i++)
				{
					if(a[i].val) continue;
					if(a[i].ma==a[i].x)
						x=a[i].y,y=a[i].z;
					else if(a[i].ma==a[i].y)
						x=a[i].x,y=a[i].z;
					else if(a[i].ma==a[i].z)
						x=a[i].x,y=a[i].y;
					ans+=max(x,y);
				}
			}
			//cout<<"\n";
			//cout<<ans<<"\n";
			cout<<(tot+ans)/2<<"\n";
		}
	}
	return 0;
}
