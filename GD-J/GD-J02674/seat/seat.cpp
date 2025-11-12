#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
int a[N],n,m,ai[N],a1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.ans","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a1 = a[1];
	sort(a+1,a+n*m+1);
	int k = 0;
	for (int i=1;i<=n*m;i++){
		ai[n*m-i+1] = a[i];
		if (a[i] == a1){
			k = n*m-i+1;
		}
	}
	int b = 0;
	if ((k+n-1)/n%2 == 0){
		if (k%n == 0){
			b = 1;
		}else{
			b = n-k%n+1;
		}
	}else{
		if (k%n == 0){
			b = n;
		}else{
			b = k%n;
		}
	}
	cout<<(k+n-1)/n<<" "<<b;
	return 0;
}
