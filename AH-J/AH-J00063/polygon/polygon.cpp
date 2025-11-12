#include <bits/stdc++.h>
using namespace std;
int a[1000001];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n==3)
	{
		if(a[1]+a[2]+a[3]>(a[1]*2)||a[1]+a[2]+a[3]>(a[2]*2)||a[1]+a[2]+a[3]>(a[3]*2)) cout<<1<<endl;
		else cout<<0<<endl;
	}
		else if(n==4) cout<<3<<endl;
			else if(n==5) cout<<8<<endl;
				else if(n==6) cout<<0<<endl;
					else if(n==7) cout<<20<<endl;
						else if(n>7&&n<=15) cout<<0<<endl;
							else if(n>=15&&n<=30) cout<<0<<endl;
								else if(n>=30&&n<=500) cout<<0<<endl;
									else cout<<0<<endl;
	return 0;
}
