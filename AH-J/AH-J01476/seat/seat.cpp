#include<bits/stdc++.h>
using namespace std;
int n,m,c;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int b[10][10];
	c=n*m;
	for(int i=1;i<=c;i++)
		cin>>a[i];
	int rcj=a[1];
	for(int i=1;i<=c;i++){
		int maxn=i;
		for(int j=i+1;j<=c;j++){
			if(a[j]>a[maxn])
				maxn=j;
		}
		swap(a[i],a[maxn]);
	}
	int s=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++)
				b[i][j]=a[s++];
		}
		else{
			for(int j=n;j>=1;j--)
				b[i][j]=a[s++];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==rcj)
			cout<<i<<' '<<j<<' ';
		}
	}
	return 0;
	}
