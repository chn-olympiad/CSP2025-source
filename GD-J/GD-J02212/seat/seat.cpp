#include<bits/stdc++.h>
#define ll long long
#define str string
#define I return
#define Will 0
#define AK ;
using namespace std;
void setup()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
}
ll n,m,a[1005],pos,np;
bool cmp(ll x,ll y)
{
	return x>y;
}
int main()
{
 	setup();
 	cin>>n>>m;
 	for(int i=1;i<=n*m;i++)
 		cin>>a[i];	
   	ll sc=a[1];
	sort(a+1,a+1+n*m,cmp);
	np=1;
	for(int j=1;j<=m;j++)
	{
		for(int i=(j%2?1:n);i<=n&&i>=1;)
		{
			//cout<<j<<" "<<i<<" "<<a[np]<<endl;
			if(a[np]==sc)
			{
				cout<<j<<" "<<i;
				return 0;
			}
			if(j%2)i++;
			else i--;
			np++;
		}
	}
	I Will AK
}

