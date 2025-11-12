#include<bits/stdc++.h>
using namespace std;
long long a[1000];
long long n,m,r;
int main(){
	freopen("seat.in","r",in)
	freopen("seat.out","w",out)
	cin>>n>>m;
	for(int i = 1;i <= n*m;i++){
		cin>>a[i];
	}
	long long k = a[1];
	for(int i = 1;i <= n*m;i++){
		for(int j = 1;j <= i;j++){
			if(a[i] > a[j]){
				int q = a[i];
				a[i] = a[j];
				a[j] = q;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		if(a[i] == k){
			if(i % n != 0){
				if((i / n + 1) % 2 == 1){
					cout<<i / n + 1<<" "<<i % m;
				}else{
					cout<<i / n + 1<<" "<<i % m + 1;
				}
			}else{
				cout<<i / n<<" "<<i / (i / n);
			}
		}
	}
	return 0;
}

