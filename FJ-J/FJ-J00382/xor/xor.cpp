#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N = 500010;
ll n,k,a[N],tot,f[1010][1010],s[1010][1010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i = 1;i <= n;i++)
		cin>>a[i];
	for(ll i = 1;i <= n;i++)
		s[i][i] = a[i],f[i][i] = (a[i]==k);
	for(ll l = 2;l <= n;l++)
	{
		for(ll i = 1;i <= n-l+1;i++)
		{
			ll j = i+l-1,p = 0;
			for(ll mi = i;mi < j;mi++)
			{
				p = f[i][mi]+f[mi+1][j];
				s[i][j] = s[i][mi]^s[mi+1][j];
				//cout<<i<<" "<<j<<" "<<mi<<" "<<p<<" "<<f[i][mi]<<" "<<f[mi+1][j]<<" "<<f[i][j]<<endl; 
				//cout<<"end:"<<p<<endl;
				if(p > f[i][j])	f[i][j] = p;
				p = 0;
			}
			if(f[i][j] == 0&&s[i][j] == k) f[i][j] = 1; 
//			cout<<i<<","<<j<<":"<<f[i][j]<<endl;
			
		}
	}
	
	cout<<f[1][n];
	return 0;
}
/*





1 1 1 1 1 1 1 1













f[l][r]
	4 2
a	2 1 0 3
s	2 
f[1][1] = 1
f[2][2] = 0
f[3][3] = 0
f[4][4] = 0
f[1][2] = f[1][1]+f[2][2] + (s[1][1]^s[2][2]==k?1:0)  = 1
f[2][3] = 0
f[3][4] = 0
f[1][3] = f[1][2]+f[3][3] + (s[1][2]^s[3][3]==k?1:0)  =  1
f[2][4] = f[2][3]+f[4][4] + (s[2][3]^s[4][4]==k?1:0)  =  1
f[1][4] = f[1][1]+f[2][4] + (s[1][2]^s[3][4]==k?1:0)  =  1 
*/
