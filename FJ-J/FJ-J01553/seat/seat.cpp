#include <bits/stdc++.h>
using namespace std;

long long n,m,a[110],x,t;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	long long l=n*m;
	for(long long i=1;i<=l;i++){
		cin >> a[i];
	}
	x=a[1];
	stable_sort(a+1,a+1+l,greater<long long>());
	for(long long i=1;i<=l;i++){
		if(a[i]==x){
			t=i;
			break;
		}
	}
	cout << (t+n-1)/n << " ";
	t%=n*2;
	if(t==0){
		t=n*2;
	}
	if(t<=n){
		cout << t;
	}else{
		cout << n-(t-n)+1;
	}
	return 0;
}
