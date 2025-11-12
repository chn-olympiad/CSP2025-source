#include<bits/stdc++.h>
using namespace std;
int n,m;
int v[1005];
int f[1005][1005];
bool cmp(int xx,int yy){
	return xx>yy;
}
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>v[i];
	}	
	int x=v[1];
	sort(v+1,v+1+n*m,cmp);
	int weizhi=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				f[j][i]=v[++weizhi];
			}
		}else{
			for(int j=n;j>=1;j--){
				f[j][i]=v[++weizhi];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
	
			if(f[i][j]==x){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	
	}
	return 0;
}
