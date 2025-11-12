#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],q[11][11],num,k; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	num=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++){
			if(i%2==0) q[j][i]=a[n*m-n*i+j];
			else q[j][i]=a[n*m-n*i+n-j+1];
			}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(q[j][i]==num) cout<<i<<" "<<j;
	fclose(stdin);
	fclose(stdout);
	return 0;
}