#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<cmath>
using namespace std;
using ll=long long;
#define File_IO 1
#define debug 0
int gcd(int a,int b)
{
	if(b)while((a%=b)&&(b%=a));
	return a+b;
}
void Ex_gcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		//1a+0=gcd(a,0)
		return;
	}
	Ex_gcd(b,a%b,y,x);
	y-=std::floor(a/b)*x;
	//b(x1)+(a-floor(a/b)*b)(y1)=gcd(a,b)
	//a(y1)+b(x1-floor(a/b)*y1)=gcd(a,b)
}
const int maxn=1e5+1;
int n;
struct node
{
	int d[4];
	int& operator[](int inx)
	{
		return d[inx];
	}
}a[maxn];
int cha[maxn];
vector<int>bu[4];
int ans;
void solve()
{
	ans=0;
	cin>>n;
	for(int j=1;j<=3;j++)bu[j].clear();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
			cin>>a[i][j];
		int max_bu=0,max_a=0;
		for(int j=1;j<=3;j++)
			if(a[i][j]>=max_a)
				max_bu=j,max_a=a[i][j];
		bu[max_bu].push_back(i);
		ans+=max_a;
		cha[i]=1e9;
		for(int j=1;j<=3;j++)
			if(j!=max_bu)
				cha[i]=min(cha[i],max_a-a[i][j]);
	}
	for(int j=1;j<=3;j++)
	{
		int chaa=bu[j].size()-(n/2);
		if(chaa<=0)continue;
		sort(bu[j].begin(),bu[j].end(),
		[=](int x,int y)
		{
			return cha[x]<cha[y];
		}
		);
		for(int i=0;i<chaa;i++)
		{
			ans-=cha[bu[j][i]];
		}
	}
	cout<<ans<<endl;
}
int main()
{
	#if File_IO
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	#endif
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}
