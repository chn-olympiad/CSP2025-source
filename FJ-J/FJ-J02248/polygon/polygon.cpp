#include<bits/stdc++.h>
using namespace std;
int n,a[100001],ans=0;
void dfs(int p,int z,int zz){
	int s=0;
	if(p==zz){
		return;
	}
	if(s>a[p]*2) ans++;
	for(int i=z;i<=n;i++){
		s+=a[i];
		return dfs(p+1,z+1,zz);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		dfs(0,0,i);
	}	
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
