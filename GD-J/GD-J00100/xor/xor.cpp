#include<bits/stdc++.h>
using namespace std;
const long long N = 500010;
int n,k,ans=0,unuse=0;
long long e_num[N]={0};
bool y_num[N] = {0};
int e(int x,int idx,bool f){
	if(x == k && y_num[idx]){
		for(int i=idx;i>=1;i--){
			e_num[i]=1;
		}
		ans++;
		return 0;
	}
	if(idx>n){
		return 0;
	}
	++idx;
	return e(e_num[idx] xor x,idx,0);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",e_num[i]);
	}
	for(int i=1;i<=n;i++){
		if(e_num[i] == k){
			ans++;
			continue;
		}
		unuse = e(e_num[i],i,1);
	}
	printf("%d",ans);
	return 0;
}
