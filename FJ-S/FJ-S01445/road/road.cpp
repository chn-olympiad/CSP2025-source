#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+5;
long long n,m ,k,sum=0,a[N],b[15][N],s[N];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i];
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		s[i]=a[i];
		sum+=s[i];
	}
	sort(s+1,s+m+1,cmp);
	cout<<sum-2*s[m]-1;
	return 0;
}
