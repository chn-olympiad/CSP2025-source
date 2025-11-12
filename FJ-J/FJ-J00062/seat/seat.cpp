#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int abc(int x,int y){
	if	(x>y) return x;
	else return y;
}
int c,r;
int main(){
	feropen("seat.in","r",stdin);
	feropen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s[n*m+1];
	for(int i=1;i<=n*m;i++) cin>>s[i];
	sort(s+1,s+n*m,abc);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(s[n*i+j]==a[1][1]) c=i;r=j;
		}
	}
	if(c%2!=0) r=n-r+1;
	cout<<c<<" "<<r;
	return 0;
}
