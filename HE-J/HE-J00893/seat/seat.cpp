#include<bits/stdc++.h>
using namespace std;
int b[150][150];
int a[10005];
bool cmp(int u,int v){
	return u>v;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int star=a[1];
	sort(a+1,a+1+n*m,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				b[j][i]=a[++cnt];
			}
		}else{
			for(int j=1;j<=n;j++){
				b[j][i]=a[++cnt];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==star){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}
