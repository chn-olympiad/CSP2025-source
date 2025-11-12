#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int rnk=1;
	for(int i=2;i<=n*m;i++){
		if(a[i]>a[1])rnk++;
	}
	int r=(rnk+n-1)/n,c=(rnk%n==0?n:rnk%n);
	if(r%2==0)c=n-c+1;
	cout<<r<<" "<<c;
	return 0;
}
