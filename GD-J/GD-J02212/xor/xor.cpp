#include<bits/stdc++.h>
#define ll long long
#define str string
#define I return
#define Will 0
#define AK ;
using namespace std;
const ll N=5*1e5+5;
void setup()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
}
ll n,k,from,to,a[N],ans;
int main()
{
 	setup();
 	cin>>n>>k;
 	for(int i=1;i<=n;i++)
 		cin>>a[i];
 	for(int i=1;i<=n;)
	{
		ll now=0,pos=0;
		bool ok=false;
		for(int j=i;j<=n;j++)
		{
			now^=a[j];
			//cout<<i<<" "<<j<<" "<<now<<endl;
			if(now==k)
			{
				ok=true;
				i=j+1;
				break;
			}
		}
		if(ok)ans++;	
		else i++;
	}	
	cout<<ans;
	I Will AK
}

