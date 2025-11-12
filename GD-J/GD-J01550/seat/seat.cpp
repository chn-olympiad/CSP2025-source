#include <bits/stdc++.h>
using namespace std;
int n,m,a[505],f,f1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[(i-1)*m+j];
	f=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m+1;i++){
		if(f==a[i]){
			f1=i;
			break;
		}
	}
	cout<<(f1+n-1)/n<<" ";
	if((f1+n-1)/n%2==1&&f1%n!=0)
		cout<<f1%n;
	else if((f1+n-1)/n%2==1&&f1%n==0)
		cout<<n;
	else if((f1+n-1)/n%2==0&&f1%n==0)
		cout<<1;
	else
		cout<<n-f1%n+1;
	return 0;
}
