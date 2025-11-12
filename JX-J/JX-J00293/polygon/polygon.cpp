#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
bool f[5005];
long long ans,mod=998244353;

bool cmp(char a,char b){
	return a>b;
}

void dfs(int m,int maxy,int cnt,int idx){
	if(m>=3&&cnt>maxy*2){
		ans++;
	}
	for(int i=idx+1;i<n;i++){
		if(f[i]==0){
			f[i]=1;
			dfs(m+1,max(maxy,a[i]),cnt+a[i],i);
			f[i]=0;
		}
	}
	return;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		f[i]=1;
		dfs(1,a[i],a[i],i);
		f[i]=0;
	}
	cout<<ans%mod;
	
	return 0;
}
