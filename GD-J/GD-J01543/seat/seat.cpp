#include<iostream>
#include<algorithm>
using namespace std;
int n,m,k,tot,sc,a[105];
int ps[105][105];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	k = n*m;
	for(int i =1;i<=k;i++){
		cin>>a[i];
	}
	sc = a[1];
	sort(a+1,a+k+1,cmp);
	for(int i =1;i<=m;i++){
		if(i%2==1){
			for(int j =1;j<=n;j++){
				ps[j][i] = a[++tot];
			}
		}
		else{
			for(int j =n;j>=1;j--){
				ps[j][i] = a[++tot];
			}
		}
	}
	for(int i =1;i<=n;i++){
		for(int j =1;j<=m;j++){
			if(ps[i][j]==sc){
				cout<<j<<" "<<i<<"\n";
				return 0; 
			}
		} 
	}
	return 0;
}
