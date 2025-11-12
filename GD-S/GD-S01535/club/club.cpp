#include<bits/stdc++.h>
using namespace std;
bool st;
const int N=1e5+6668;
int a[N][6],n;
namespace sub1{
	const int M=205;
	int f[M][M][M];
	void mainn()
	{
		//clear();
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				for(int k=0;k<=n;k++) f[i][j][k]=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=min(i,n/2);j++)
			{
				for(int k=0;k<=min(i,n/2);k++)
				{
					if(j+k>i-1) continue;
					int res=i-1-j-k;
					if(j<n/2)f[i][j+1][k]=max(f[i][j+1][k],f[i-1][j][k]+a[i][2]);
					if(k<n/2)f[i][j][k+1]=max(f[i][j][k+1],f[i-1][j][k]+a[i][3]);
					if(res<n/2) f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i][1]);
				}
			}
		}
		int ans=0;
		for(int j=0;j<=n/2;j++) 
		for(int k=0;k<=n/2;k++) 
		{
			ans=max(ans,f[n][j][k]);
		}
		cout<<ans<<"\n";
	}
}
namespace sub{
	bool ban[N];
	vector<int>v,v2,v3;
	int O,O1,O2;
	bool cmp(int x,int y)
	{
		return a[x][O]>a[y][O];
	}
	bool cmp2(int x,int y)
	{
		return a[x][O1]+a[y][O2]>a[x][O2]+a[y][O1];
	}
	void mainn()
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		int azz=0;
		for(O=1;O<=3;O++)
		{
			v.clear(),v2.clear(),v3.clear();
			for(int i=1;i<=n;i++)
			{
				ban[i]=0;
				int mx=0;
				for(int j=1;j<=3;j++) if(j!=O) mx=max(mx,a[i][j]);
				if(a[i][O]>mx) v.push_back(i);
				else if(a[i][O]==mx) v2.push_back(i);
			}
			sort(v.begin(),v.end(),cmp);
			sort(v2.begin(),v2.end(),cmp);
			int len=v.size(),len2=v2.size();
			for(int i=0;i<min(len,n/2);i++) ban[v[i]]=1;
			int r=0;
			while(len<n/2&&r<len2)
			{
				ban[v[r]]=1;
				r++,len++;
			}
			int ans=0;
			for(int i=1;i<=n;i++) 
			{
				if(!ban[i]) v3.push_back(i);
				else ans+=a[i][O];
			}
			for(int i=1;i<=3;i++) 
			{
				if(i!=O) 
				{
					O1=i;
					break;
				}
			}
			for(int i=3;i>=1;i--)
			{
				if(i!=O)
				{
					O2=i;
					break;
				}
			}
			sort(v3.begin(),v3.end(),cmp2);
			int len3=v3.size(),sum=0;
			for(int i=0;i<len3;i++)
			{
				sum+=a[v3[i]][O1];
			}
			int az=(len3<=n/2)?sum:0;
			int oc=0,sum2=0;
			for(int i=len3-1;i>=0;i--)
			{
				oc++;
				sum-=a[v3[i]][O1];
				sum2+=a[v3[i]][O2];
				if(max(oc,len3-oc)<=n/2) az=max(az,sum+sum2);
			}
			azz=max(azz,ans+az);
		}
		cout<<azz<<"\n";
	}
}
bool ed;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	cerr<<(&st-&ed)/1048576.000;
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--) 
	{
		cin>>n;
		if(n<=200) sub1::mainn();
		else sub::mainn();
	}
} 
