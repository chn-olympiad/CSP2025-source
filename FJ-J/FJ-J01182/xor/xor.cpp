#include<bits/stdc++.h>
using namespace std;
int ans,n,k,a[541451];
bool f_a=true;
void dfs(int prev,int sum){
	if(prev>n){
		ans=max(ans,sum);
	}
	else{
		int tot=0;
		bool f=false;
		for(int i=prev;i<=n;i++){
			tot^=a[i];
			if(tot==k){
				dfs(i+1,sum+1);
				f=true;
				break;
			}
		}
		if(!f)
		dfs(prev+1,sum);
	}
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	std::ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		if(a[i]!=1){
			f_a=false;
		}
	}
	if(f_a)
	ans=n/2;
	else
	dfs(1,0);
	cout<<ans;
	return 0;
}

