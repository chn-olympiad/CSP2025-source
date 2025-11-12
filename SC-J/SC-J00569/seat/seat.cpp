#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define ex exit(0);
#define pii pair<int,int> 
#define sinzo return 
#define code 0 
const int N=2e6+10;
const int mod=1e9+7;
int n,m,k,cnt,sum,ans;
int a[N],b[N],c[N];
bool vis[N];
using namespace std;
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1)k=a[i];
	}
	sort(a+1,a+1+n*m);
	int l=1,r=n*m;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(a[mid]<k)
		{
			l=mid+1;
		}
		else r=mid-1;
		if(a[mid]==k)
		{
			ans=mid;
			break;
		}
		if(l<1||r>n*m)
		{
			while(1)
			{
				cout<<"sinzo rp++\n";
			}
		}
	}
	int x=0;
	ans=n*m-ans+1;
	l=ans;
	x=l/n;
	l=l%n;
	if(l%n!=0)x++;
	
	cout<<x<<' ';
	if(x%2==1)
	{
		cout<<l;
		ex;
	}
	else 
	{
		cout<<n-l+1;
		ex;
	}
	sinzo code;
} 
/*
3 3
92 93 94 95 96 97 98 99 100
3 3
94 95 96 97 98 99 100 93 92

*/