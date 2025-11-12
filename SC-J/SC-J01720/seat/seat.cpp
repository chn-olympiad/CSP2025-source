#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out ","w",stdout);
	int a[13][13]={},d[105]={};
	int n,m,s=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>d[i];
	} 
	s=d[1];
	sort(d+1,d+n*m+1);
	int k=n*m; 
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				a[j][i]=d[k];
				k--;
			}
		}else{
			for(int j=1;j<=n;j++){
				a[j][i]=d[k];
				k--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==s){
				cout<<j<<" "<<i<<"\n";
				break;
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<a[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	return 0;
}