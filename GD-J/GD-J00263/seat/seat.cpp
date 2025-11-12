#include<bits/stdc++.h>
using namespace std;
int mp[100][100];	
int a[10000];
int n,m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	const int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				cnt++;
				mp[j][i]=a[cnt];
				if(a[cnt]==r) {
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				cnt++;
				mp[j][i]=a[cnt];
				if(a[cnt]==r) {
					cout<<i<<" "<<j<<endl;
					return 0; 
				}
			} 
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<mp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	return 0;
}
