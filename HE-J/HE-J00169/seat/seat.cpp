#include<bits/stdc++.h>
using namespace std;
int kc[15][15];
int n,m;
int a[105];
int smR;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	cin>>n>>m;
	cin>>smR;
	a[1]=smR;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	int p,t=1;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				kc[j][i]=a[t++];
			}
		}else{
			for(int j=n;j>=1;j--){
				kc[j][i]=a[t++];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(kc[i][j]==smR){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
