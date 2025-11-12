#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,a[N],s=1,f1,f2;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int t=0;
	t=n*m;
	cin>>a[1];
	for(int i=2;i<=t;i++)
	{
		cin>>a[i];
		if(a[i]>a[1])
		 s++;
	}
	f1=(s+n-1)/n;
	f2=s%n;
	if(f2==0)
	 f2=n;
	if(f1%2==1)
	{
		cout<<f1<<" "<<f2;
	}else{
		cout<<f1<<" "<<n-f2+1;
	}
	return 0;
}
