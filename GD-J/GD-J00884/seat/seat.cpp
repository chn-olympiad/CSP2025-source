#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,x,h,l,t,a[2000008],f[2500][2500];
int cmp(int i,int j){
	return i>j;
}
main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++) f[j][i]=a[++t];
		} 
		else for(int j=m;j>=1;j--) f[j][i]=a[++t];
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(f[i][j]==x) return cout<<j<<" "<<i,0;
		}
	}
	return 0;
}
