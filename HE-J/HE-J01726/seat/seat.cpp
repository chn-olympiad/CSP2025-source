#include<bits/stdc++.h>
using namespace std;
int n,m;
int x=0,y=0;
int a[105],b[105],r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=m*n;i++){
		b[i]=a[m*n-i+1];
		if(b[i]==r){
			if(i%n==0){
				if(i/n%2==0) cout<<i/n<<' '<<1;
				else cout<<i/n<<' '<<n;
			}
			else{
				cout<<i/n+1<<' ';
				if((i/n+1)%2==0) cout<<n-i+i/n*n+1;
				else cout<<i-i/n*n;
			}
		}
	}
	return 0;
} 
