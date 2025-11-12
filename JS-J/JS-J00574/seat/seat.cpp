#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,fs[101],xr,f=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>fs[i];
	xr=fs[1];
	//cout<<xr<<endl;
	sort(fs+1,fs+1+n*m);
	for(int i=n*m;i>=1;i--){
		//cout<<fs[i]<<" ";
		if(fs[i]==xr) f=n*m-i+1;
		//cout<<f<<endl;
	}
	int c,r,f2;
	c=f/n;
	if(f%n!=0) c=c+1;
	//cout<<f<<" "<<n<<" ";
	f2=f%c;
	if(f2==0) f2=n;
	if(c%2==0) r=n-f2+1;
	else r=f2;
	cout<<c<<" "<<r<<endl;
	return 0;
}
