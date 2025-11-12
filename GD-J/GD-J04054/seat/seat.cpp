#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1010];
int b[110][110];
int p;
int xiaor;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	xiaor=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				b[i][j]=a[++p];
			}
		}else{
			for(int i=n;i>=1;i--){
				b[i][j]=a[++p];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==xiaor){
				cout<<j<<" "<<i;
				return 0; 
			}
		}
	}
	return 0;
}

