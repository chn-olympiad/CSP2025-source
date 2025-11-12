#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b[105][105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int z=n*m;
	for(int i=1;i<=z;i++){
		cin>>a[i];
	} 
	int k=a[1];
	int cnt=0,q=1,j=1;
	sort(a+1,a+z+1,cmp);

	for(int i=1;i<=m;i++){
		if(q%2!=0)
			for(int j=1;j<=n;j++){
				b[i][j]=a[++cnt];
			}
		else{
			for(int j=n;j>=1;j--){
				b[i][j]=a[++cnt];
			}
		}
		q++;
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++){
			if(b[i][j]==k){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	return 0;
}
