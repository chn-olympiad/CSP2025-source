#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int a[200];
int b[20][20];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int ans=a[1];
	sort(a+1,a+n*m+1,cmp);
	int h=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				b[i][j]=a[h];
				h++;
			}
		}
		if(i%2==0){
			for(int j=n;j>=1;j--){
				b[i][j]=a[h];
				h++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ans==b[i][j]){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
