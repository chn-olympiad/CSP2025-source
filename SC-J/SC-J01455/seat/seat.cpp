#include<bits/stdc++.h>
using namespace std;
long long n,m,sum;
long long a[105],r,k;
bool cmp(long long A,long long B){
	return A>B;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			k=i;
			break;
		}
	}
	sum=((k-1)/n)+1;
	if(sum%2==1){
		k=k-(sum-1)*n;
		cout<<sum<<" "<<k;
	}
	else{
		k=k-(sum-1)*n;
		cout<<sum<<" "<<n-k+1;
	}
	//100+100
	return 0;
}
