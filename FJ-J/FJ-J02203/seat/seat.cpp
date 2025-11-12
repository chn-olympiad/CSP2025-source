#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	cin>>n>>m;
	int R=0;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	R=a[1];
	sort(a+1,a+n*m+1);
	int num=0;
	for(int i=n*m;i>=1;i--)
		if(a[i]>R)
			num++;
		else
			break;
	cout<<1+num/n<<" ";
	if((1+num/n)%2==0)
		cout<<n-num%n;
	else
		cout<<num%n+1;
	return 0;
}
