#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[105];
long long b[15][15],kl;
bool cmp(int a1,int b1){
	return a1>b1;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	kl=a[1];
	sort(a+1,a+n*m+1,cmp);
	bool p=0;
	int d=1;
	for(int i=1;i<=m;i++){
		if(p==0){
			for(int j=1;j<=n;j++){
				b[i][j]=a[d];
				d++;
			}
			p=1;
		}else{
			for(int j=n;j>=1;j--){
				b[i][j]=a[d];
				d++;
			}
			p=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==kl){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}