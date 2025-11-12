#include<bits/stdc++.h>
using namespace std;
int n,m,a[11][11],b[101],c=-1,b1,d,flag;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	b1=n*m+1;
	for(int i=1;i<=n*m;i++)cin>>b[i];
	d=b[1];
	sort(b+1,b+n*m+1);
	for(int i=1;i<=m;i++){
		c*=-1;
		if(c==1)
			for(int j=1;j<=n;j++)a[j][i]=b[--b1];
		else
			for(int j=n;j>=1;j--)a[j][i]=b[--b1];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)
			if(a[j][i]==d){
				cout<<i<<" "<<j;
				flag=1;
				break;
			}
		if(flag==1)break;
	}
	return 0;
}
