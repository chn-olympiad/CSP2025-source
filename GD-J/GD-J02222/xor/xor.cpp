#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+15;
int n,k;
int ans=0;
int a1[5505][2];
int T=1;
bool vis[MAXN]={false};
int a[MAXN],b[MAXN]={0};
int dfs(int d,int d2,int cn){
	for(int i=d;i<=T;i++){
		if(a1[i][0]>d2){
			ans=max(dfs(i,a1[i][1],cn+1),cn);
		}
	}
	return cn;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
		b[1]=a[1];
	}
	int x;
	if(k==0){
		cout<<1<<endl;
		return 0;
	}
	else {
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int t=b[j]^b[i-1];
				if(t==k){
					a1[T][0]=i;
					a1[T][1]=j;
					T++;
				}
			}
		}
		dfs(1,a1[1][1],1);
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
