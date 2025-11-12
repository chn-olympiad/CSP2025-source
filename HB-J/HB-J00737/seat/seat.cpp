#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,cnt=0,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n*m;i++){
		if(a[1]>a[i]){
			cnt++;
		}else if(a[1]<a[i]){
			sum++;
		}
	}
	if(cnt==n*m-1){
		cout<<1<<" "<<1;
		return 0;
	}else if(sum==n*m-1){
		cout<<m<<" "<<n;
		return 0;
	}
	for(int i=1;i<=n*m;i++){
		if(cnt==n*m-i){
			if(i<=n){
				cout<<1<<" "<<i;
				return 0;
			}else{
				cout<< i/n<<" "<<i%n+2;
				return 0;
			}
		}else if(sum==n*m-i){
			if(i<=n){
				cout<<m<<" "<<sum;
				return 0;
			}else{
				cout<<m<<" "<<n*m-i-i-2;
			}
		}
	}
	return 0;
}
