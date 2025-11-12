#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,inf=1e9+10;

int a[N][3],d[N][3],f[N];
void Solve(){
	int n,c[3]={},sum=0;
	cin>>n;
	for(int i=1;i<=n;++i){
		for(int j:{0,1,2})
			cin>>a[i][j],d[i][j]=j;
		sort(d[i],d[i]+3,[&](int j1,int j2){
			return a[i][j1]>a[i][j2];
		});
		++c[d[i][0]],sum+=a[i][d[i][0]];
	}
	for(int j:{0,1,2})if(c[j]>n/2){
		int m=0;
		for(int i=1;i<=n;++i)
			if(d[i][0]==j)f[++m]=a[i][j]-a[i][d[i][1]];
		std::sort(f+1,f+m+1);
		for(int i=1;i<=m-n/2;++i)
			sum-=f[i];
	}
	cout<<sum<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
//	freopen("club5.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--)Solve();
	return 0;
}
