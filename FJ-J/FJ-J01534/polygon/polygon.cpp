#include<bits/stdc++.h>
using namespace std;
int n,a[5010],b[5010],m;
long long h;
bool f[5010];
void dfs(int x,int l,int mx){
	if(x>m){
		if(l>2*mx){
			h++;
			h%=998244353;
		}
		return;
	}
	for(int i=b[x-1]+1;i<=n;i++){
		if(f[i]==false){
			f[i]=true;
			b[x]=i;
			dfs(x+1,l+a[i],max(mx,a[i]));
			f[i]=false;
		}
	}
	return;
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
		m=i;
		for(int j=1;j<=n;j++){
			f[j]=false;
			b[j]=0;
		}
		dfs(1,0,0);
	}
	cout<<h<<endl;
	return 0;
}
