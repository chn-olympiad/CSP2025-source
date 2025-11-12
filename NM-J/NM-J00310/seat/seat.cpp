#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a>b;
}
int a[105],s[15][15],b[15],num2=0;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
int n,m,num=1;
cin>>n>>m;
for(int i=1;i<=n*m;i++) cin>>a[i];
int ming=a[1];
sort(a+1,a+1+n*m,cmp);
for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++) 
	{
		b[j]=a[num];
		num++; 
		}
		if(i%2==0){
			sort(b+1,b+1+m);
			for(int k=1;k<=m;k++) s[i][k]=b[k];
		}
		else{
			for(int k=1;k<=m;k++) s[i][k]=b[k];
		}
}
for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++)if(s[i][j]==ming){ cout<<i<<" "<<j;return 0;}
}
}
