#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110],s[110][110];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int c=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j%2==1)
				s[i][j]=a[n*j-n+i];
			else if(j%2==0)
				s[i][j]=a[n*j-i+1];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==c) cout<<j<<" "<<i;
		}
	}
	return 0;
}  
