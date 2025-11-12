#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],s,k,h,l,v[15][15],w=0;
bool cmp(long long p,long long q){
	return p>q;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		if(i&1){
			for(int j=1;j<=n;j++){
				v[i][j]=a[++w];
			}
		}
		else{
			for(int j=n;j>=1;j--){
				v[i][j]=a[++w];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(v[j][i]==s){
				printf("%lld %lld",j,i);
				return 0;
			}
		}
	}
	return 0;
}
