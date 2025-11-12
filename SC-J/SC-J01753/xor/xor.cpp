#include<bits/stdc++.h>
using namespace std;
long long k;
int n;
long long num[500005]{};
long long ans=0;
long long dfs(int l,int r){
	if(l>=r)return 0;
	long long ans1=0;
	long long maxn=0;
	for(int i=l;i<r;i++){
		ans1=0;
		for(int j=i;j<r;j++){
			ans1=(ans1^num[j]);
			if(ans1==k){
				maxn=max(maxn,1+dfs(j+1,r));
			}else{
				maxn=max(maxn,dfs(j+1,r));
			}
		}
	}
	return maxn;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	cout<<dfs(0,n);
	return 0;
} 