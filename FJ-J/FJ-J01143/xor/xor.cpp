#include <iostream>
using namespace std;
int n,k,x,p;
struct P{
	int x, y;
}a[110];
bool cmp(P x,P y){
	return x.x>y.x||x.x==y.x&&x.y>y.y;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0)
	{
		if(n%2==0)
		{
			cout<<n/2;
		}
		else
		{
			cout<<n/2+1;
		}
		return 0;
	}
	if(k==1)
	{
		for(int i=1; i<=n; i++)
		{
			cin>>x;
			if(x==1)
			{
				p++;
			}
		}
		cout<<p;
		return 0;
	}
	return 0;
}

