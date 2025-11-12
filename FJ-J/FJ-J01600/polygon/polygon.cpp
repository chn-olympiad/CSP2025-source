#include <bits/stdc++.h>
using namespace std;
int n,a[5005],s=0;
const int m=998244353;
void db(int x,int y,int z,int k)
{
	if(a[x+1]<y&&k>1)
	{
		s=(s+1)%m;
	}
	if(z==x) return ;
	else
	{
		z++;
		k++;
		db(x,y+a[z],z,k);
		k--;
		db(x,y,z,k);
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<n;i++) db(i,0,0,0);
	cout<<s;
	return 0;
}
