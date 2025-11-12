#include<iostream>
#include<algorithm>
using ll=long long;
const ll mod(998244353);
using namespace::std;
int d[1000],c[1000],p[1000];
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,c1,c2,i;
	char ch;
	ll ans(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	  cin>>ch,d[i]=ch-48,
	  p[i]=i;
	for(i=1;i<=n;i++)
	  cin>>c[i];
	do
	{
		c1=0,c2=0;
		for(i=1;i<=n;i++)
		{
			if(c1>=c[p[i]]||!d[i])
			{c1++;continue;}
			c2++;
		}
		if(c2>=m)(ans+=1)%=mod;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans;
	return ~~(0-0);
}
//Àî¹ðÅ£Àî¹ðÅ£Àî¹ðÅ£Àî¹ðÅ£Àî¹ðÅ£Àî¹ðÅ£Àî¹ðÅ£Àî¹ðÅ£ 
