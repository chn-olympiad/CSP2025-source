#include<bits/stdc++.h>
using namespace std;
int a[105];
int a1[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 0;i < n*m;i++){
		cin>>a[i];
	}
	int t = a[0],t1=0;
	sort(a,a+n*m);
	if(a[0]==t1){
		cout<<1<<" "<<1;
		return 0;	
	}
	if(a[n*m]==t1){
		cout<<m<<" "<<n;
		return 0;
	}
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= n;j++){
			if(i % 2 != 0){
				a1[i][j]=a[t1];
			}else{
				a1[i][n-j+1]=a[t1];
			}
			t1++;
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(a1[i][j]==t){
				cout<<i<<" "<<j;
				break;
			}
		}	
	}
	return 0;
}
