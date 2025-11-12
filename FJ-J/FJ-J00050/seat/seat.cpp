#include<bits/stdc++.h>
using namespace std;
int f[13][13],ff[105];
bool cmp(int a,int b){
	return a>b;
}
bool ji(int s){
	return s%2==0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i,j,nm,shu=1,tt;
	cin>>n>>m;
	nm=n*m;
	for(i=1;i<=nm;i++)scanf("%d",&ff[i]);
	tt=ff[1];
	sort(ff+1,ff+nm+1,cmp);
	for(j=1;j<=m;j++){
		if(ji(j)){
			for(i=n;i>=1;i--){
				f[i][j]=ff[shu];
				shu++;
			}
		}else{
			for(i=1;i<=n;i++){
				f[i][j]=ff[shu];
				shu++;
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)if(f[i][j]==tt){
			cout<<j<<' '<<i;
			return 0;
		}
	}
	return 0;
}
