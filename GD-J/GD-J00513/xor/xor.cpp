#include<bits/stdc++.h>
using namespace std;
int n,k,ans,cnt;
int a[500005];
int f[500005];
void dfs(int x){
	int t=1;
	if(a[x]!=k){
		if(f[x]==-1) t=-1;
		else x=f[x];
	}
	cnt+=t;
	ans=max(ans,cnt);
	for(int i=x+1;i<n;i++){
		dfs(i);
	}
	cnt-=t;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	bool fa=0,fb=0;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1) fa=1;
		if(a[i]!=0&&a[i]!=1) fb=1;
	}
	if(!fa){
		printf("%d",n/2);
	}else if(!fb){
		for(int i=0;i<n;i++){
			if(a[i]==k){
				ans++;
			}else if((a[i+1]!=a[i])==k&&i+1<n){
				ans++;
				i++;
			}
		}
		printf("%d",ans);
	}else{
		for(int i=0;i<n;i++){
			int t=a[i];
			bool flag=0;
			for(int j=i+1;j<n;j++){
				t^=a[j];
				if(t==k){
					f[i]=j;
					flag=1;
					break;
				}
			}
			if(!flag) f[i]=-1;
		}
		for(int i=0;i<n;i++){
			cnt=0;
			dfs(i);
			ans=max(ans,cnt);
		}
		printf("%d",ans);
	}
	return 0;
}

