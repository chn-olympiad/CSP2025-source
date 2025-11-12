#include<bits/stdc++.h>
using namespace std;
int sab(int a1,int a2){
	return a1>a2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+1];
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	int b=a[1];
	sort(a+1,a+1+m*n,sab);
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			int x=i/n,y=i%n;
			if(y==0){
				y=n;
				x--;
			}
			if(x%2==0){
				cout<<x+1<<' '<<y;
			}else{
				cout<<x+1<<' '<<n-y+1;
			}
			break;
		}
	}
	return 0;
}