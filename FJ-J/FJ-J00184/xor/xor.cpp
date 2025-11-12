#include<bits/stdc++.h>
using namespace std;
int n,a[500005],pre[500005],ans[500005],k,last[1050000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		pre[i]=pre[i-1]^a[i];
		last[pre[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int num=k^a[i]^pre[i-1];
		ans[i]=max(ans[last[num]]+1,ans[i-1]);
		if(a[i]==k) ans[i]=max(ans[i-1]+1,ans[i]);
	}
	printf("%d ",ans[n]);
	return 0;
}
