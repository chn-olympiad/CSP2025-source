#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int b=a[1],c,d;
	sort(a+1,a+1+m*n);
	for(int i=1;i<=n*m;i++){
		int j=n*m+1-i;	
		if(a[i]==b){
			if(j%n==0){
				c=j/n;
				d=n;
			}else{
				c=j/n+1;
				d=j%n;	
			}
		}
	}
	if(c%2==1){
		cout<<c<<" "<<d;
	}else{
		cout<<c<<" "<<n+1-d;
	}
	return 0;
}
