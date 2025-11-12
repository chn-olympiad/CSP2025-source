#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],zwb[11][11],xr;
bool cmp(int a,int b){
	return a>b;
}
void pzw(){
	bool f=1;
	int xi=1;
	for(int i=1;i<=m;i++){
		if(f){
			for(int j=1;j<=n;j++){
				zwb[j][i]=a[xi++];
			}
		}else{
			for(int j=n;j>=1;j--){
				zwb[j][i]=a[xi++];
			}
		}
		f=!f;
		
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)xr=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	pzw();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(zwb[i][j]==xr){
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}
