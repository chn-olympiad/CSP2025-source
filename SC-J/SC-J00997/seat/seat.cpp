#include<bits/stdc++.h>
using namespace std;
int n,m,a[111],num,f,n1,m1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	num=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
		if(a[i]==num){
			f=n*m-i+1;
			break;
		}
	n1=(f-1)/(2*n)*2;
	m1=(f-1)%(2*n);
	if(m1<n){
		cout<<n1+1<<' '<<m1+1;
	}else cout<<n1+2<<' '<<2*n-m1;
	return 0;
}