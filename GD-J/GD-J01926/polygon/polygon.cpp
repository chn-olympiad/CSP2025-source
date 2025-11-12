#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
int n,ans;
int a[5010],c[5010][5010];
void dfs(int id,int len){
	if(len>a[id]*2) ans=(ans+1)%p;
	for(int i=id+1;i<=n;i++){
		dfs(i,len+a[i]);
	}
}
void mm(){
	for(int i=0;i<=5005;i++){
		for(int j=0;j<=i;j++){
			if(j==0) c[i][j]=1;
			else c[i][j]=(c[i-1][j]+c[i-1][j-1])%p;
//			cout<<c[i][j]<<' ';
		}
//		cout<<'\n';
	}
}
int main(){
	mm();
	bool flag=0;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=1;
	}
	if(flag){
		sort(a+1,a+n+1);
		dfs(0,0);
	}else{
		for(int i=3;i<=n;i++){
			ans=(ans+c[n][i])%p;
		}
	}
	cout<<ans;
	return 0;
}
//#Shang4Shan3Ruo6Shui4
