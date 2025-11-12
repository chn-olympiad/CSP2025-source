#include<bits/stdc++.h>
using namespace std;
long long a[5010];
bool t[5010];
long long cni=0;
long long n;
int check(){
	long long mx=0;
	long long sum=0;
	for(int i=1;i<=n;i++){
		if(t[i]==1){
			mx=max(mx,a[i]);
			sum+=a[i];
		}
	}
	if(sum>mx*2){
		return 1;
	}else{
		return 0;
	}
}
void dfs(long long cnt,long long ans){
	if(cnt>n){
		if(ans>=3){
			if(check()==1){
				cni++;
			}
			cni=cni%998244353;
		}
		return;
	}
	t[cnt]=1;
	dfs(cnt+1,ans+1);
	t[cnt]=0;
	dfs(cnt+1,ans);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0);
	cout<<cni;	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
