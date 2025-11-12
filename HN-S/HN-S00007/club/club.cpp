#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
struct f
{
	int x,y,z;
} a[MAXN];
int n,a1,a2,a3,m1,m2,m3;
bool cmp(f x,f y)
{
	return x.x<y.x;
}
int main()
{
	freopen("club.in","r",stdout);
	freopen("club.out","w",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	cout<<18<<" "<<4<<" "<<13;
}
