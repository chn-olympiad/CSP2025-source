#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005],b[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int cnt=a[1];
	for(int i=n*m;i>1;i--)
		for(int j=1;j<=i;j++)
			if(a[j]<a[j+1])
				swap(a[j],a[j+1]);
	for(int i=1;i<=n;i++)
		b[i]=i;
	for(int i=n+1;i<=2*n;i++)
		b[i]=2*n-i+1;
	for(int i=1;i<=n*m;i++)
		if(a[i]==cnt)
			if(i%n)
				if(i%(2*n)==0)
					cout<<i/n+1<<' '<<1;
				else
					cout<<i/n+1<<' '<<b[i%(2*n)];
			else
				if(i%(2*n)==0)
					cout<<i/n<<' '<<1;
				else
					cout<<i/n<<' '<<b[i%(2*n)];
	return 0;
} 