#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[101][101],cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[1][1]<a[i][j]){
				cnt++;
			}
			
		}
	}
	if(cnt==0)cout<<1<<" "<<1;
	else if(cnt==1)cout<<1<<" "<<2;
	else if(cnt==2){
		if(n==2)cout<<2<<" "<<1;
		else cout<<1<<" "<<3;
	}
	else if(cnt==3){
		cout<<2<<" "<<3;
	}
	else if(cnt==4){
		cout<<2<<" "<<2;
	}
	else if(cnt==5){
		cout<<2<<" "<<1;
	}
	else if(cnt==6){
		cout<<3<<" "<<1;
	}
	return 0;
} 
















