#include<bits/stdc++.h>
using namespace std;
const int N=1e2+9;
long long n,m,a[N],b;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)b=a[i];
	}
	sort(a+1,a+n*m+1);
//	for(int i=1;i<=n*m;i++)cout<<a[i]<<endl;
	long long num=n*m-(lower_bound(a+1,a+n*m+1,b)-(a+1));
//	cout<<num<<endl;
	long long k=(num-1)%n+1,p=(num-1)/n;
	if(p%2==0)cout<<p+1<<" "<<k;
		else cout<<p+1<<" "<<n-k+1;
	return 0;
}