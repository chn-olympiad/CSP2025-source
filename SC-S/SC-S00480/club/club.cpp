#include<bits/stdc++.h>
using namespace std;
int z=0,n;
void f(vector<vector<int>> &a,int ux,int k,int uk1,int uk2,int uk3)
{
	if(ux>=n)
	{
		z=max(z,k);
		return ;
	}
	if(uk1<n/2) f(a,ux+1,k+a[ux][0],uk1+1,uk2,uk3);
	if(uk2<n/2) f(a,ux+1,k+a[ux][1],uk1,uk2+1,uk3);
	if(uk3<n/2) f(a,ux+1,k+a[ux][2],uk1,uk2,uk3+1);
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin>>t;
	while(t--)
	{
		cin>>n; z=0;
		vector<vector<int>> a(n,vector<int>(3));
		for(auto &x:a)
			for(auto &y:x)
				cin>>y;
		f(a,0,0,0,0,0);
		cout<<z<<'\n';
	}
	return 0;
}