#include<bits/stdc++.h>

using namespace std;

int n,m,a[100001];

bool cmp(int a,int b){
	return a>b;
}
int b[1001][1001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++) cin>>a[i];
	int R = a[1];
	sort(a+1,a+1+n*m,cmp);
	int k = 0;
	for(int i = 1;i<=n;i++){
		if(i%2==1){
			for(int j = 1;j<=m;j++) b[i][j] = a[++k];
		}else{
			for(int j = m;j>=1;j--) b[i][j] = a[++k];
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(b[i][j]==R){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}

	return 0;
}
