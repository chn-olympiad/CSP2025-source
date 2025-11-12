#include<bits/stdc++.h>
using namespace std;
int a[5005],b[5005],t[5005],t2[5005],n,ans=1;
int dfs(int x){
	int s=0;
	for(int i=1;i<=x-i;i++){
		for(int i=0;i<5005;i++)t2[i]=t[i];
		s+=dfs(i)%998244353;
		s+=dfs(x-i)%998244353;
		for(int i=0;i<5005;i++)t[i]=t2[i];
	}
	if(t[x]){
		t[x]--;
		return s+1;
	}
	else return s;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		t[a[i]]++;
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)b[i]=a[i]+(i==0?0:b[i-1]);
	for(int i=2;i<n;i++){if(b[i-1]-a[i]>=0){t[a[i]]--;ans+=dfs(a[i]);t[a[i]]++;ans%=998244353;}}
	printf("%d",ans);
	return 0;
}
