#include<bits/stdc++.h>
using namespace std;
int arr[500001],pre[500001],match[500001],n,k,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",&arr[i]);
		pre[i]=arr[i] xor pre[i-1];
	}
	for(int i=1;i<=n;++i){
		int tar=pre[i-1] xor k;
		for(int j=i;j<=n;++j)
		if(tar==pre[j]){
			match[i]=j;
			break;
		}
	}
	for(int i=1;i<=n;++i){
		if(match[i]){
			for(int j=i+1;j<=match[i];++j){
				if(match[j]&&match[j]<=match[i])match[i]=0;
			}
		}

	}
	for(int i=1;i<=n;++i){
		if(match[i]){
			for(int j=i+1;j<=match[i];++j){
				if(match[j])match[j]=0;
			}
		}
	}
	for(int i=1;i<=n;++i){
		if(match[i]){
			++ans;
		}
	}
	printf("%d",ans);
	return 0;
}