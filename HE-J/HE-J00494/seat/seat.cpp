#include<bits/stdc++.h>
using namespace std;
int n,m,a[109];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int t=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			if(i%n==0){
				cout<<i/n<<" ";
				if((i/n)%2==0) cout<<1;
				else cout<<n;
				
			}
			else{
				cout<<i/n+1<<" ";
				if((i/n+1)%2==0)cout<<n-i%n+1;
				else cout<<i%n;
				
			}
		}
	}
	return 0;
}
