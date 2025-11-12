#include <bits/stdc++.h>
using namespace std;
int a[20][20],b[110];
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m,i,j=1,t;
cin>>n>>m;
for(i=1;i<=n*m;i++){
cin>>b[i];
}t=b[1];
for(i=1;i<=n*m;i++){
	for(j=1;j<=n*m;j++){
		if(b[j]<b[j+1]){
			swap(b[j],b[j+1]);
		}
	}
}
for(i=1;i<=n*m;i++){
	if(t==b[i]){
		if(i%n==0&&i%(2*n)==0){
		cout<<i/n<<" "<<"1";
		return 0;
		}else if(i%n==0&&i%(2*n)!=0){
		cout<<i/n<<" "<<n;
		return 0;
		}else if((i/n)%2==0){
				cout<<i/n+1<<" "<<i%n;
		}
		else if((i/n)%n!=0&&i%n!=0){
				cout<<i/n+1<<" "<<n-(i%n-1);
				return 0;
		}
		else if(i<n){
		cout<<"1"<<" "<<i;
		return 0;
		} 
	}
}return 0;
}
