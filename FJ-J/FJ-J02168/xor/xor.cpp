#include<bits/stdc++.h>

using namespace std;

int n,k;
int ans,ans_1,f[500005];

int d[23]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304};

int work(int a,int b){
	int an=0;
	for(int i=20;i>=0;i--){
		an+=d[i]*(a-d[i]>=0)^(b-d[i]>=0);
	}
	return an;
}

void dfs(int x,int num){
	bool flag=0;
	for(int i=x+1;i<=n;i++){
		flag=1;
		if(!f[i]){
			dfs(i,num);
		}
		if(f[i]==k){
			dfs(i,0);
			ans++;
			continue;
		}
		int a=work(num,f[i]);
		if(a==k){
			ans++;
			dfs(i,0);
			ans--;
		}
		else{
			dfs(i,a);
		}
	}
	if(!flag){
		ans_1=max(ans,ans_1);
	}
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>f[i];
	}
	
	dfs(0,0);
	
	cout<<ans_1;
	
	return 0;
}
