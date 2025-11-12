#include<bits/stdc++.h>
using namespace std;
int n,m,c,s,z,ans;
map<long long,long long>f;
struct node
{
	int x,y;
}a[1000000];
bool cmp(node A,node B)
{
	return A.y<B.y;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		c^=x;
		if(f[m^c]!=0)
			a[++s].x=f[m^c]+1,a[s].y=i;
		if(x==m)
			a[++s].x=i,a[s].y=i;
		f[c]=i;
	}
	sort(a+1,a+s+1,cmp);
	for(int i=1;i<=s;i++)
	{
		if(a[i].x>z)
			ans++,z=a[i].y;
	}
	cout<<ans;
	
	return 0;
}	
