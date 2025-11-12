#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int rk=1;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
		if (a[i]>a[1])
			rk++;
	}
	int x=(rk-1)/n+1;
	cout<<x<<' ';
	if (x%2==1)
		cout<<rk-(x-1)*n;
	else
		cout<<n-(rk-(x-1)*n)+1;
	return 0;
}
