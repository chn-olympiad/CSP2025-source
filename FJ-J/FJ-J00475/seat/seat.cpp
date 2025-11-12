#include<bits/stdc++.h>
using namespace std;
int n,m,a[10009],b[109][109];
bool s(int yi,int er){
	return yi>er;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1,s);
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				b[i][j]=a[++cnt];
			}
		}
		else{
			for(int j=n;j>=1;j--){
				b[i][j]=a[++cnt];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(r==b[i][j]){
				cout<<i<<' '<<j;
				return 0;
			}
		}
	}
	cout<<1<<' '<<1;
	return 0;
}

