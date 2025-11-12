#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],pd,ans,ma;
void dfs(long long ge,long long xb,long long he){
	if(ge==0&&xb>=0){
		if(he-ma>ma)ans++;
		return;
	}
	else if(xb==0)return;
	else{
		dfs(ge-1,xb-1,he+a[xb]);
		dfs(ge,xb-1,he);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)pd=1;
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	else if(n==3){
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[3]+a[2]>a[1])cout<<1;
		else cout<<0;
		return 0;
	}
	else{
		sort(a+1,a+1+n);
		for(int choose=3;choose<=n;choose++){
			for(int maxx=n;maxx>=choose;maxx--){
				ma=a[maxx];
				dfs(choose-1,maxx-1,ma);
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
