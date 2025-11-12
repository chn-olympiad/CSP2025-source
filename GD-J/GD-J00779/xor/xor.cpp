#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int ans=INT_MIN;
void f(set<int> s,int d){
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			if((a[j]^a[i-1])==k){
				bool is_idx_ex=0;
				if(!s.empty()){ 
					for(int l=i;l<=j;++l){
						if(s.count(l)){
							is_idx_ex=1;
							break;
						}
					}
				}
				if(!is_idx_ex){
					for(int p=i;p<=j;++p){
						s.insert(p);
					}
					ans=max(ans,d);
					f(s,d+1);
				}
			}
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1]; //转为前缀异或和数组 
	}
	set<int> n_xxs;
	f(n_xxs,1);
	cout<<ans;
	return 0;
}
