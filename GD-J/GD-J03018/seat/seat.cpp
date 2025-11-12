#include<bits/stdc++.h>
using namespace std;
int a[10111],n,m,sum,x;
int cmp(int a,int b){
	return a>b;
}int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m,cin>>a[1],sum=a[1];
	for(int i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+1+m*n,cmp),x=1;
	for(int i=1;i<=m;i++){
		for(int j=x;j<=i*n;j++){
			if(a[j]==sum){
				cout<<i<<" ";
				if(i&1){
					cout<<j-(i-1)*n;
					return 0;
				}else {
					cout<<n-(j-(i-1)*n)+1;
					return 0;
				}
			}
		}x+=n;
	}return 0;
}
