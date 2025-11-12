#include<bits/stdc++.h>
using namespace std; 
int a[15][15];
int m,n,k,c,p=1;
int s[250];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int z=m*n;
	if(n==1&&m==1)cout<<"1"<<endl;
	for(int j=0;j<z;j++){
		cin>>s[j];
	}
	int x=s[0];
	int q=1,g=0,h=2;
	sort(s,s+z);
	reverse(s,s+z);
	for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++){
	for(int p=1;p<=z;p++){
		a[i][j]=s[p];
		if(p>=h){
		a[i][j]=s[p+n];
		g++;
		if(g>=m){
			a[i][j]=s[p-n+1];
			g=0;
			h++;
		}
		}
	}
	}
	}
	for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++){
		if(a[i][j]=x){
		c=i;
		k=j;
		}
	}
	}
	cout<<c<<" "<<k<<endl;
	return 0;
}
