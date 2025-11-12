#include<bits/stdc++.h>
using namespace std;
long long n,m,q,ans;
long long a[110];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>q;
	for(int i = 1; i <= (n * m) - 1; i++){
		cin>>a[i];
	}
	sort(a+1,a+(n*m));
	int o = 1;
	for(int i = (n * m) - 1; i >= 1; i--){
		if(a[i] > q && a[i-1] < q){
			ans = o + 1; 
			break;
		} 
		o++;
	}
	int i = ans / n;
	int j = ans % n;
	if(j == 0){
		cout<<i<<" "<<n<<endl;
	}else{
		if((i + 1) % 2 == 0){
			cout<<i + 1<<" "<<n - (j - 1)<<endl;
		}else{
			cout<<i + 1<<" "<<j<<endl;
		}
	}
	return 0;
}
