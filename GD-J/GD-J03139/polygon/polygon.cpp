#include<bits/stdc++.h>
using namespace std;
const int m=1e7+10;
int a[m],f[m],v[m],n,ans,i=3;
void dfs(int x){
	if(x>=i+1){
		int sum=0,big=0;
		for(int i=1;i<=x;i++){
			sum+=f[i];
			if(f[i]>=big)big=f[i];
		}if(sum>big*2)ans++;
		return ;
	}
	for(int i=f[x];i<=n;i++){
		if(v[a[i]]==0){
			f[x]=a[i];
			v[a[i]]=1;
			dfs(x+1);
			v[a[i]]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("poligon.out","w",stdout);
	cin>>n;	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(i=3;i<=n;i++){
		dfs(1);
	}cout<<ans;
	return 0;
}
