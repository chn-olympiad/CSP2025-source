#include<bits/stdc++.h>
using namespace std;
long long a[200];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	cin>>a[1];
	long long cnt = 0;
	for(long long i = 2;i <= n * m;i++){
		cin>>a[i];
		if(a[i] > a[1]){
			cnt++;
		}
	}
	if(cnt % n != 0) cout<<(cnt / n) + 1<<" ";
	else cout<<(cnt / n)<<" ";
	if((cnt / n) % 2 == 0){
		if(cnt % n != 0) cout<<(cnt % n) + 1;
		else cout<<n;
	}else{
		if(cnt % n != 0) cout<<n - (cnt % n) + 1;
		else cout<<1;
	}
	return 0;
}
