#include<bits/stdc++.h>
using namespace std;
int n,m;
int nm[110];
int a[50][50];
int sco;
int len;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>nm[i];
	}
	sco=nm[1];
	sort(nm+1,nm+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i%2==1){
				a[j][i]=nm[++len];
			}else a[n-j+1][i]=nm[++len];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==sco){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}

