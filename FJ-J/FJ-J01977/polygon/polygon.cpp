#include<bits/stdc++.h>
using namespace std;
int n;
int a[5001];
int ans[5001];
long long cnt;
const long long F=998244353;
bool is_poly(int n){
	int Max=ans[0];
	int sum=ans[0];
	for(int i=1;i<n;i++){
		if(Max<ans[i]){
			Max=ans[i];
		}
		sum+=ans[i];
	}
	return sum>(2*Max);
}
void dfs(int s,int k){
	if(k>=3){
		if(is_poly(k)){
			cnt+=1;
			cnt%=F;
		}
	}
	for(int i=s;i<n;i++){
		ans[k]=a[i];
		dfs(i+1,k+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	dfs(0,0);
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
