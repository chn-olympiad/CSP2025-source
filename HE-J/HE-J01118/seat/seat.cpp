#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[100],b[11][11],c;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	c=a[1];
	sort(a+1,a+n*m+1,cmp);
	int sum=1;
	for(int i=1;i<=n;i++){
		if(i%2!=0){
			for(int j=1;j<=m;j++){
				b[i][j]=a[sum];
				sum++;
			}
		}
		if(i%2==0){
			for(int j=m;j>=1;j--){
				b[i][j]=a[sum];
				sum++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==c){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
