#include<bits/stdc++.h>
using namespace std;
int n,m,a[111],s=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	for(int i=2;i<=n*m;i++){
		if(a[1]<a[i])s++;
	}
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				s--;
				if(s==0){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				s--;
				if(s==0){
					cout<<i<<" "<<j;
					return 0;
				}
			 }
		}
	}
	return 0;
}
