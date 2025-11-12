#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define ll long long

using namespace std;
ll ans;
const int N = 200010;

struct Point
{
	int a,b;
}v[N];

vector<Point>A,B;

inline int Cnt(Point x)
{
	return (x.a >= 0) + (x.b >= 0);
}

bool cmp(const Point& x,const Point& y)
{
	return max(x.a,x.b) > max(y.a,y.b);
}

bool cmp1(const Point& x,const Point& y)
{
	return max(-x.a,x.b - x.a) > max(-y.a,y.b - y.a);
}

bool cmp2(const Point& x,const Point& y)
{
	return max(-x.b,x.a - x.b) > max(-y.b,y.a - y.b);
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		int n,i,x,cnt = 0;
		ans = 0;
		cin>>n;
		for(i = 1;i <= n;i++)
		{
			cin>>v[i].a>>v[i].b>>x;
			ans+=x;
			v[i].a-=x;
			v[i].b-=x;
		}
		for(i = 1;i <= n;i++) if(Cnt(v[i]) > 0) cnt++;
		if(cnt > n / 2)
		{
			A.clear();
			B.clear();
			for(i = 1;i <= n;i++)
			{
				if(Cnt(v[i]))
				{
					if(v[i].a > v[i].b) A.push_back(v[i]);
					else B.push_back(v[i]);
				}
			}
			for(i = 0;i < A.size();i++) ans+=A[i].a;
			for(i = 0;i < B.size();i++) ans+=B[i].b;
			if(A.size() > n / 2)
			{
				sort(A.begin(),A.end(),cmp1);
				for(i = 0;i < A.size() - n / 2;i++) ans+=max(-A[i].a,A[i].b - A[i].a);
			}
			else if(B.size() > n / 2)
			{
				sort(B.begin(),B.end(),cmp2);
				for(i = 0;i < B.size() - n / 2;i++) ans+=max(-B[i].b,B[i].a - B[i].b);
			}
		}
		else
		{
			sort(v + 1,v + n + 1,cmp);
			for(i = 1;i <= n / 2;i++) ans+=max(v[i].a,v[i].b);
		}
		cout<<ans<<endl;
	}
	return 0;
}
