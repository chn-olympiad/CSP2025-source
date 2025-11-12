#include<bits/stdc++.h>
using namespace std;
long long n,m,R;
long long a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(long long i=1;i<=n*m;i++){
		if(a[i]==R){
			if((i/n)%2==0){
				if(i%n!=0){ 
					cout<<i/n+1<<' '<<i%n;
					return 0;
				}
				if(i%n==0){ 
					cout<<i/n<<' '<<1;
					return 0;
				}
			}
			if((i/n)%2==1){
				if(i%n!=0){
					cout<<i/n+1<<' '<<n-i%n+1;
					return 0;
				}
				if(i%n==0){
					cout<<i/n<<' '<<n;
					return 0;
				}
			}
		}
	}
	return 0;
}
