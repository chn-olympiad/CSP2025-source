#include<bits/stdc++.h>
using namespace std;
int s[15][15],i,j,tt,pos;
int n,m,poss=1;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int k=1;k<=n*m;k++) cin>>a[k];
	tt=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	
//	for(int k=1;k<=n*m;k++) cout<<a[k]<<" ";
//	cout<<"\n";
	 
	for(int k=1;k<=n*m;k++){
		if(a[k]==tt) pos=k;
	}
	
//	cout<<tt<<"\n";
//	cout<<pos<<"\n";
	
	for(j=1;j<=m;j++){
		if(j%2==1){
			for(i=1;i<=n;i++) {
				s[i][j]=poss;
				poss++;
			}
		}
		else {
			for(i=n;i>=1;i--){
				s[i][j]=poss;
				poss++;
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++) {
			if(s[i][j]==pos) cout<<j<<" "<<i<<"\n";
		}
	}

	return 0;
}
