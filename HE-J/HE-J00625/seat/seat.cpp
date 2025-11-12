#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>m;
	int a[n+1][m+1],b[n*m+1];
	for(int i=0;i<=n*m;i++){
		b[i];
		cin>>b[i];
	}
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++)
			if(b[j]<b[j+1])swap(b[j],b[j+1]);
	}
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			q++;
			a[i][j]=b[q];
			if(b[q]>b[0])cout<<i<<" "<<j;
			return 0;
		}
	}
}
