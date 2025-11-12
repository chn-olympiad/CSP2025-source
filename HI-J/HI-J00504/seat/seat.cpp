#include <bits/stdc++.h>
using namespace std;
const int N=110;
int a[N];
int b[N][N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int use=a[1];
	sort(a+1,a+n*m+1,cmp);
	int idx=1;
	for(int i=1;i<=n;i++){
		if(i%2==0){
			for(int j=m;j>=1;j--){
				b[i][j]=a[idx];
				idx++;
			}
		}else{
			for(int j=1;j<=m;j++){
				b[i][j]=a[idx];
				idx++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==use){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}

