#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a_r,a,wz;
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>n>>m;
	long long i;
	cin>>a_r;
	wz=1;
	for(i=2;i<=n*m;i++)
	{
		cin>>a;
		if(a>a_r)
		{
			wz++;
		}
	}
	long long ls=(wz+n-1)/n;
	long long hs=0;
	if(ls%2==0)
	{
		hs=(n-(wz%n))%n+1;
	}
	else
	{
		hs=(wz-1)%n+1;
	}
	cout<<ls<<" "<<hs;
	
	return 0;
} 
