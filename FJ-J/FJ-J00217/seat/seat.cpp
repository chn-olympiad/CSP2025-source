#include<bits/stdc++.h>
using namespace std;//O(n^2+n),ma sa ka o re ha ka su?
int n,m,a[114514],c,r,b[20][20];
bool cmp(int x,int y){
	return x>y;
}
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
int nihon=n*m;
for(register int i=0;i<nihon;i++){
	cin>>a[i];
}
int c=a[0];
sort(a,a+nihon,cmp);int genshin=0;
for(register int j=0;j<m;j++){
	if(j%2==0||j==0){
	for(register int i=0;i<n;i++){
		b[i][j]=a[genshin];
		genshin++;
		if(b[i][j]==c){
			cout<<j+1<<" "<<i+1;
			return 0;
		}
	}	
	}
	else{
		for(register int i=n-1;i>=0;i--){
		b[i][j]=a[genshin];
		genshin++;
		if(b[i][j]==c){
			cout<<j+1<<" "<<i+1;
			return 0;
		}
	}	
	}
	
}
return 0;
}
