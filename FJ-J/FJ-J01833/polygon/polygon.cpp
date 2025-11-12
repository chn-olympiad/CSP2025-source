#include<bits/stdc++.h>
using namespace std;
int n,a[5001],vis[5001],sum,cnt;
bool cmp(int a,int b){
	return a>b;
}
int cvis(){
	sum=0;
	int num=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==1){
			if(sum==0){
				num=a[i];
			}
			sum+=a[i];
		}
	}
	if(sum>num*2)return 1;
	else return 0;
}
void dfs(int s){
	if(s==0)return;
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]!=1){
			vis[i]=1;
			dfs(i-1);
			if(cvis())cnt++;
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=3;i<=n;i++){
		dfs(i);
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
  return 0;
}
