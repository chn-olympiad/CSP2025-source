#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[15][15]={},s[105],t,a1;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>s[i];
	}
	a1=s[0];
	sort(s,s+n*m);
	t=n*m-1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				a[i][j]=s[t];
				t--;
			}
		}	
		else{
			for(int j=n;j>=1;j--){
				a[i][j]=s[t];
				t--;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==a1){
				cout<<i<<" "<<j;
				break;
			}
		}
	}
	return 0;
}