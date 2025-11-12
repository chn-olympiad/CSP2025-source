#include <bits/stdc++.h>
using namespace std;
int a[5005];unsigned long long c=0;
void dfs(int x,int y,int z,int w,int v,int n){
	if(x<y){
		if(z>w)c++;
		return;
	}for(int i=v+1;i<=n-x+y;i++){
		if(x==y)w=a[i];
		else z+=a[i];
		dfs(x,y+1,z,w,i,n);
		if(x==y)w=0;
		else z-=a[i];
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;bool f=0;unsigned long long ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)f=1;
	}if(!f){
		unsigned long long x=1;
		unsigned long long y=1;
		for(int i=3;i<=n;i++){
			x=1;y=1;
			for(int j=n;j>n-i;j--){
				x*=j;y*=n-j+1;
				if(n-j+1>=y){
					x/=n-j+1;y/=n-j+1;
				}
			}x/=y;
			ans+=x%998244353;
		}cout<<ans%998244353;return 0;
	}sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		dfs(i,1,0,0,0,n);ans+=c;ans%=998244353;c=0;
	}cout<<ans%998244353;
	fclose(stdin);fclose(stdout);
	return 0;
}
