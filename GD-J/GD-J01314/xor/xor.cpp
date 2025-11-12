#include<bits/stdc++.h>
using namespace std;

int n,k,aans;
int a[500005],b[500005];
void dfs(int now,int l,int r,int ans){
	//cout<<now<<" "<<r<<" "<<ans<<endl;
	if(b[l]!=0){
		aans=max(ans+1,aans);
		for(int i=b[l]+1;i<=n;i++){
			dfs(a[i],i,i,ans+1);
		}
		return ;
	}
	if(r>n){
		return ;
	}
	if(now==k){
		if(b[l]==0){
			b[l]=r;
		}
		//cout<<"S:"<<now<<" "<<r<<" "<<ans<<endl;
		aans=max(ans+1,aans);
		for(int i=r+1;i<=n;i++){
			dfs(a[i],i,i,ans+1);
		}
		return ;
	}
	dfs(now^a[r+1],l,r+1,ans);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(a[i],i,i,0);
	}
	cout<<aans<<endl;
	return 0;
}
