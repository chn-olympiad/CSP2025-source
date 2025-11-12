#include<bits/stdc++.h>
using namespace std;
int n,m,xr,a[105],wz=1,ls,hs;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1)
			xr=a[i];
		else if(a[i]>xr)
			wz++;
	}
	ls=(wz-1)/n+1,hs=wz%n;
	if(hs==0)
		hs=n;
	if(ls%2==0)
		hs=n-hs+1;
	cout<<ls<<" "<<hs;
	return 0;
}
