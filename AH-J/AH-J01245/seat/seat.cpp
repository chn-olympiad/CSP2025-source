#include<bits/stdc++.h>
using namespace std;
const int N=101;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long a[N];
	long long n,m;
	cin>>n>>m;
	long long sum=1;
	int nm=n*m;
	cin>>a[1];
	for(int i=2;i<=nm;i++){
		cin>>a[i];
		if(a[i]>a[1]) sum++;
	}
	if(sum%n==0){
		cout<<sum/n<<' '<<n;
	}
	else{
		cout<<sum/n+1<<' ';
		if((sum/n)%2==0) cout<<sum%n;
		else cout<<n-(sum%n)+1;
	}
	return 0;
}
