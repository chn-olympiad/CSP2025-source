#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int inf=0x3f3f3f3f;
const ll INF=1e16;
const int N=1e5+10;
//int dp[205][205][205];
struct stud1{
	int a,b,c;
}arr[N];
int maxx=-inf;
//void init(int n)
//{	
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n;j++)
//			for(int k=1;k<=n;k++)
//				dp[i][j][k]=0;
//
//}
void rfs(int n,int a,int b,int c,int x,int ans)
{
	if(x>n)
	{
//		cout<<dp[x-1][a][b][c]<<endl;
//		cout<<" a "<<a<<" b "<<b<<" c "<<c<<" x "<<x<<" ans "<< ans<<endl;
		maxx=max(maxx,ans);
		return ;
	}
	if(a+1<=n/2)
	{
		rfs(n,a+1,b,c,x+1,ans+arr[x].a);
	}
	if(b+1<=n/2)
	{
		rfs(n,a,b+1,c,x+1,ans+arr[x].b);
	}
	if(c+1<=n/2)
	{
		rfs(n,a,b,c+1,x+1,ans+arr[x].c);
	}

}
bool cmp1(stud1 a,stud1 b)
{
	return a.a>=b.a;
}
bool cmp2(stud1 a,stud1 b)
{
	return abs(a.a-a.b)>=abs(b.a-b.b);
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--)
	{
		int n;cin>>n;
//		init(n);
		maxx=-inf;
		bool fa=1,fb=1;
		for(int i=1;i<=n;i++)
		{
			cin>>arr[i].a>>arr[i].b>>arr[i].c;
//			scanf("&d&d&d",arr[i].a,arr[i].b,arr[i].c);
			if(arr[i].b!=0||arr[i].c!=0) fa=false;
			if(arr[i].c!=0) fb=false;
		}
		if(n<=30)
		{
			rfs(n,0,0,0,1,0);
			cout<<maxx<<endl;continue;
		if(fa)
		{
			ll ans=0;
			sort(arr+1,arr+n+1,cmp1);
			for(int i=1;i<=n/2;i++)
			{
				ans+=arr[i].a;
			}
			cout<<ans<<endl;
			continue;
		}
		if(fb)
		{
			ll ans=0;
			sort(arr+1,arr+n+1,cmp2);
//			for(int i=1;i<=n;i++)
//			{
//				cout<<arr[i].a<<" "<<arr[i].b<<endl;
////			}
//			cout<<"d"<<endl;
			int aa,bb;aa=bb=0;
			for(int i=1;i<=n;i++)
			{
				if(arr[i].a<arr[i].b)
				{
					ans+=arr[i].b;
					bb++;
					continue;
				}
				else 
				{
					ans+=arr[i].a;
					aa++;
					continue;
				}
				if(aa>=n/2)
				{
//					cout<<"dd"<<endl;
					for(int j=i+1;j<=n;j++)ans+=arr[j].b;
					break;
				}
				if(bb>=n/2)
				{
//					cout<<"dd"<<endl;
					for(int j=i+1;j<=n;j++)ans+=arr[j].a;
					break;
				}
			}
			cout<<ans<<endl;
			continue;
		}
		
		}
		else{
			ll ans=0;
			for(int i=1;i<=n;i++)
			{
				ans+=max(max(arr[i].a,arr[i].b),max(arr[i].b,arr[i].c));
			}
			cout<<ans<<endl;
		}
	}
		
	
	return 0;
}

