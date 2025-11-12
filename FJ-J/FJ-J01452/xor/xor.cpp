#include<bits/stdc++.h>
using namespace std;
int n;
int k;
long long a[100000];
int sum;
int l[1000000];
int r[1000000];
int f;
int maxn=-999999;
void dfs(int step,int hhh){
	if(step>n){
		if(hhh>=maxn){
			maxn=hhh;
			return;
		}
		return;
	}
	for(int i=1;i<=f;i++){
		if(l[i]==step){
			dfs(r[i]+1,hhh+1);
		}else{
			dfs(step+1,hhh);
		}
	}
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sum=0;
			if(i<=j){
				sum=a[i];
				for(int k=i+1;k<=j;k++){
					sum^=a[k];
				}
				if(sum==k){
					f++;
					l[f]=i;
					r[f]=j;
				}
			}else{
				continue;
			}
		}
	}
	dfs(1,0);
	cout<<maxn;
	return 0;
} 
