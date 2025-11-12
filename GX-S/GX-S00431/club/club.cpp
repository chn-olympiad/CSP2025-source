#include <bits/stdc++.h>
using namespace std;
#define ll long long
int T,n;
ll f[100001];
struct S
{
	ll x,y,z;
} a[100001];
ll fu(int i,int m1,int m2,int m3)
{
	ll ma=0;
	//if(i==n)
	//{
		if(m1<n/2) ma=max(ma,a[i].x);
		if(m2<n/2) ma=max(ma,a[i].y);
		if(m3<n/2) ma=max(ma,a[i].z);
		if(i==n)return ma;
	//}
	if(m1<n/2) ma=max(ma,a[i].x+fu(i+1,m1+1,m2,m3));
	if(m2<n/2) ma=max(ma,a[i].y+fu(i+1,m1,m2+1,m3));
	if(m3<n/2) ma=max(ma,a[i].z+fu(i+1,m1,m2,m3+1));
	return ma;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--)
	{
		cin >> n;
		for (int i = 1;i<=n;i++)
		{
			ll x,y,z;
			cin >> x >> y >> z;
			a[i]=(S){x,y,z};
		}
		cout << fu(1,0,0,0) << endl;
	}
	return 0;
}
