#include <iostream>
#include <algorithm>
using namespace std;

int n,ma;
int a[5010];
bool b[5010];
int yh[5010][5010];
long long s,u;

void check(int l){
//	cout<<u<<" "<<a[l];
	if(u>a[l])s++;
	if(s>=998244353)s-=998244353;
}

void dfs(int k,int t,int l){
	if(k==n+1){
		if(t>=3)check(l);
		return;
	}
	b[k]=1;u+=a[l];
	dfs(k+1,t+1,k);
	b[k]=0;u-=a[l];
	dfs(k+1,t,l);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	if(ma==1){
		yh[1][0]=yh[1][1]=1;
		for(int i=2;i<=n;i++){
			yh[i][0]=1;
			for(int j=1;j<=i;j++){
				yh[i][j]=(yh[i-1][j-1]+yh[i-1][j])%998244353;
			}
		}
		for(int i=3;i<=n;i++){
			s=(s+yh[n][i])%998244353;
		}
		cout<<s;
	}else{
		sort(a+1,a+n+1);
		dfs(1,0,0);
		cout<<s;
	}
	return 0;
}
