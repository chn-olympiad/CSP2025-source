#include<bits/stdc++.h>
using namespace std;
int n,m,a[103],r=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1);
	int num=0;
	for(int i=n*m;i>=1;i--)
		if(a[i]==r) {num=n*m-i+1;break;}
	if(num%n==0)
	{
		cout<<num/n<<" ";
		if((num/n)%2==1) cout<<m;
		else cout<<1;
	}
	else
	{
		cout<<num/n+1<<" ";
		if((num/n+1)%2==1) cout<<num-m*(num/n);
		else cout<<m-(num-m*(num/n))+1;
	}
	return 0;
}
