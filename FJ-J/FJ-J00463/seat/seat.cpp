#include<bits/stdc++.h>
using namespace std;
int m,n,k[100007],p[100007],i=1,j=1,x=1,y=1,l[100007];
bool s;
int main(){
	//freopen ("seat.in","r",stdin);
	//freopen ("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cin>>p[i]; 
			l[i]=p[i];
		}
	}
	i=j=1;
	sort(l+1,l+n+1);
	do{
		k[i]=p[i];
		if(s)i--;
		else i++;
		if(i==n&&!s)j++,s=1;
		if(i==1&&s)j++,s=0;
	}while(i==n&&j==m);
	cout<<i<<j;
	return 0;
}
