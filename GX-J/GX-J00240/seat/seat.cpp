#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<stack>
#include<cmath>
using namespace std;
int n,m,a[101],a1,x;
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	a1=a[1];sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){x=i;break;}
	}
	//for(int i=1;i<=n*m;i++)cout<<a[i]<<" ";
	if(x<=n){cout<<1<<" "<<x;return 0;}
	int col=ceil(x*1.0/n);col--;
	int row=(col+1%2==0)?n-(x-col*n)+1:x-col*n;
	cout<<col+1<<" "<<row;
	return 0;
}
