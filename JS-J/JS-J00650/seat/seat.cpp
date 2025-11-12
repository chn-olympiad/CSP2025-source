#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
long i=1,j=1,n,m;
cin>>n>>m;
long nm=n*m;
int a[nm+1];
for(int wr=1;wr<=nm;wr++){
	cin>>a[wr];
}
long long s=a[1],num[n+1][m+1];
sort(a+1,a+nm+1,cmp);
long d=1;
while(i<=n&&j<=m){
		num[i][j]=a[d];
		d++;
	if(i==n&&j==m) break;
	else if(j%2==1&&i!=n) i++;
	else if(i==n&&j%2==1) j++;
	else if(j%2==0&&j!=1) i--;
	else if(j%2==0&&i==1) j++;
}
for(long i=1;i<=n;i++){
	for(long j=1;j<=m;j++){
		if(num[i][j]==s) 
			cout<<j<<' '<<i;
		}
}
return 0;
}
