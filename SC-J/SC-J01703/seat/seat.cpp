#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int a[105];
int n,m;
int zuowei[105][105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int r;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	int cnt=0;
	int i=1;
	while(i<=n){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				zuowei[i][j]=a[++cnt];
			}
		}else{
			for(int j=m;j>=1;j--){
				zuowei[i][j]=a[++cnt];
			}
		}
		i++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(zuowei[i][j]==r){
				cout<<i<<" "<<j;
			}
		}
	}
}