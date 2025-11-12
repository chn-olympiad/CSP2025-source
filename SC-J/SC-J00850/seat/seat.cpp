#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1];
	for(int j=1;j<=n*m;j++){
		for(int i=2;i<=n*m;i++){
			if(a[i]>a[i-1])
			swap(a[i],a[i-1]);
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			if(i%n==0){
				cout<<i/n<<n;
			}else{
				cout<<i/n+1<<i%n;
			}
		}
	}
}