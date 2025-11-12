#include<bits/stdc++.h>
using namespace std;
map<int,int> a;
int n;
bool am[5050];
int f(int h,int m,int ma)
{
	if(m>n)
	{
		int k=0;
		for(int i=1;i<=n;i++)
		{
			if(am[i]==true) k++;
		}
		if(k<3) return 0;
		if(h>ma*2) return 1;
		else return 0;
	}
	int rans=0;
	if(m>0)
	{
		am[m]=true;
		rans+=f(h+a[m],m+1,a[m])%998244353;
	}		
		am[m]=false;
		rans+=f(h,m+1,ma)%998244353;
		return rans;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=1;j<i;j++)
		{
			if(a[j]>a[i]) swap(a[j],a[i]);
		}
	}
	cout<<f(0,0,0);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
