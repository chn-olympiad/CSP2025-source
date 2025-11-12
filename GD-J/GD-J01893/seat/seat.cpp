#include<bits/stdc++.h>
using namespace std;
int a[10001],s[51][51];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+1+n*m);
	int k=1;
	for(int i=m;i>=1;i--){
		if(i%2==0){
			for(int j=1;j<=n;j++){
				s[j][i]=a[k];
				k++;
			}
		}else{
			for(int j=n;j>=1;j--){
				s[j][i]=a[k];
				k++;
			}
		}
		
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<s[i][j];
//			if(s[i][j]==r){
//				cout<<i<<" "<<j;
//				return 0;
//			}
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==r){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
}
