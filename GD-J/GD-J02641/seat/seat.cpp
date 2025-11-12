#include<bits/stdc++.h>
using namespace std;
int a[200000],n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}int tmp=a[1];
	int rank=1;
	for(int i=2;i<=n*m;i++){
		if(a[1]<a[i]) rank++;
	}//cout<<rank;
	int now=0;
	for(int j=1;j<=m;j++){
		if(j%2==0){
			for(int i=n;i>=1;i--){
				now++;
				if(now==rank){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
		else{
			for(int i=1;i<=n;i++){
				now++;
				if(now==rank){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	return 0;
}
//3 3 94 95 96 97 98 99 100 93 92
