#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1145],g;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}g=a[1];
	sort(a+1,a+n*m+1);
	int id=n*m+1;
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				if(a[--id]==g){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				if(a[--id]==g){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
} 
