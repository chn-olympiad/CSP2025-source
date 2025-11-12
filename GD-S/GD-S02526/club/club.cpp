#include <bits/stdc++.h>

using namespace std;

const int N=1e5+5;

int n;
int A[N],B[N];
int maxx[N];
int a[N],b[N],c[N];

bool a_judge()
{
	for(int i=0;i<n;i++)
	{
		if(b[i]!=0)
			return 0;
		if(c[i]!=0)
			return 0;
	}
	
	return 1;
}

bool b_judge()
{
	for(int i=0;i<n;i++)
		if(c[i]!=0)
			return 0;
			
	return 1;
}

int Maxx(int a,int b,int c)
{
	return max(max(a,b),c);
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin>>T;
	while(T)
	{
		int ans=0;
		int ans1=0,ans2=0,ans3=0;
			
		memset(a,0,sizeof(0));
		memset(b,0,sizeof(0));
		memset(c,0,sizeof(0));
		memset(A,0,sizeof(0));
		memset(B,0,sizeof(0));
		
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			A[i]=a[i];B[i]=b[i];
			maxx[i]=Maxx(a[i],b[i],c[i]);
		}
			
		if(a_judge())
		{
			sort(a,a+n);
			for(int i=n/2;i<n;i++)
				ans+=a[i];
		}
		else if(n==2)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(i!=j)
					{
					ans1=0;
					ans1=max(a[i]+b[j],ans1);
					ans1=max(a[i]+c[j],ans1);
					ans1=max(b[i]+a[j],ans1);
					ans1=max(b[i]+c[j],ans1);
					ans1=max(c[i]+b[j],ans1);
					ans1=max(c[i]+a[j],ans1);
					}	
				}
				ans=+ans1;
			}		
		}
		else 
		{
			
			for(int i=0;i<n;i++)
				ans+=maxx[i];
		}
		
		cout<<ans<<"\n";
			
		T--;
	}
	
}
