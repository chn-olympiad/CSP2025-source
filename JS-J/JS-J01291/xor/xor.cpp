#include<bits/stdc++.h>
using namespace std;
int n,k;
int cnt=0;
int a[500010];
int vis[500010]={0};
void dfs(int s,int e){
	int sum=0;
	if((e-s)==2){
		cnt++;
		return;
	}
	for(int j=s;j<=e;j++){
		if(vis[j]){
			break;
		}
		sum=sum^a[j];
		if(sum==k){
			dfs(s,j);
			cnt++;
			break;
		}
	}
	for(int i=s;i<=e;i++){
		vis[i]=1;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","s",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int sum=0;
		if(vis[i]){
			continue;
		}
		for(int j=i;j<=n;j++){
			if(vis[j]){
				break;
			}
			if(a[j]!=k){
				sum=sum^a[j];
				if(sum==k){
					dfs(i,j);
					break;
				}
			}else{
				cnt++;
				vis[j]=1;
				break;
			}
		}
		vis[i]=1;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
}
