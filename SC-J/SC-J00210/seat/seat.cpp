#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,xming;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	xming=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==xming){
			i=n*m-i+1;
			if(i%n==0){
				if((i/n)%2==0){
					cout<<i/n<<' '<<1;
					return 0;
				}else{
					cout<<i/n<<' '<<m;
					return 0;
				}
			}else{
				cout<<i/n+1<<' ';
				if((i/n+1)%2==1){
					cout<<i%n;
					return 0;
				}else{
					cout<<m-(i%n)+1;
					return 0;
				}
			}
		}
	}
	return 0;
} 