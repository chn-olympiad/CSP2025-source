#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[225],tot=0,xgd=0,cnt=0;
bool f; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]>a[1]){
			tot++;	
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			f=1;
			xgd=0;
		}
		else{
			f=0;
			xgd=n+1;
		} 
		for(int j=1;j<=n;j++){
			cnt++;
			if(f==1) xgd++;
			else xgd--;
			if(cnt==tot+1){
				cout<<i<<' '<<xgd;
			}
		}
	}
	return 0;
}
