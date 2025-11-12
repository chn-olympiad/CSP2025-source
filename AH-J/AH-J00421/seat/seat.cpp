#include<bits/stdc++.h>
using namespace std;
long long a[105];
long long n,m,t,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[(j-1)*n+i];
		}
	}t=a[1];
	sort(a+1,a+n*m+1,greater<long long>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			x=i/n+(i%n!=0);
			y=i%n;
			cout<<x<<' ';
			if(x%2==1){
				if(y==0){
					cout<<n;
				}else cout<<y;
			}else{
				if(y==0){
					cout<<1;
				}else cout<<n-y+1;
			}break;
		}
	}
	return 0;
}
