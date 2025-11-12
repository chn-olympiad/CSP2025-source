#include<bits/stdc++.h>
using namespace std;
int main{
	freopen("seat.in","r",stdin)
	freopen("seat.out","w",stdout)
	
	int n,m,a[1001][1001],b[1001],c,d,r,e=1,l;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
			cin>>b[i];	
	}
	l=b[1]
	
	for(int i=1;i<=n*m;i++){
		if(b[i]<b[i+1]){
			d=b[i];
			b[i]=b[i+1];
			b[i+1]=d;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=m;j++){
			a[i][j]=b[e];
			e++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=m;j++){
			if(a[i][j]==l){
				c=i;
				r=j;
				break;
			}
		}
	}
	cout<<c<<r;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
