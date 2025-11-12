#include<bits/stdc++.h>
using namespace std;
long long cnt=0;
int a[5010],s[5010];
int h[5010],su[5010];
int n;
void dfs(int cur,int bs,int sum,int mx){
	if(su[n]-su[cur-1]+sum<=mx) return;
	if(bs>=3&&sum>mx*2){
		bool f=1;
		for(int i=1;i<=bs;i++){
			if(s[i]){
				if(s[i]!=h[i]){
					f=0;
					break;
				}
			}
		}
		if(f==0){
			cnt=(cnt+1)%998244353;
			for(int i=1;i<=bs;i++) h[i]=s[i];
		}
	}
	if(cur>n) return;
	dfs(cur+1,bs,sum,mx);
	s[cur]=1;
	dfs(cur+1,bs+1,sum+a[cur],max(mx,a[cur]));
	s[cur]=0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		su[i]=su[i-1]+a[i];
	}
	dfs(1,0,0,0);
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

