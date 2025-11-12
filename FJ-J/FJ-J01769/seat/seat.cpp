#include<bits/stdc++.h>
using namespace std;
int n,m,a[10000],k[10000],x,que;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--) if(a[i]==x) que=n*m-i+1;
	if(que<=n){
		cout<<1<<' '<<que;
		return 0;
	}
	if(que==n*m){
		cout<<m<<' '<<n;
		return 0;
	}
	cout<<(que-1)/n+1<<' ';
	int num=(que-1)/n+1;
	int sum=que%n;
	if(num%2) cout<<sum;
	else cout<<n-sum+1;
	return 0;
}
