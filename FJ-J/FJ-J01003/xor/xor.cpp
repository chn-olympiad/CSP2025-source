#include<bits/stdc++.h>
using namespace std;
int a[500005],n,k,c,ans;
bool fa,fb,st[500005];
void dfs(int l,int r,int sum){
	if(sum==k){
		ans++;
		for(int i=l;i<=r;i++)st[i]=1;
	}
	if(r<=n){
		for(;r<n;){
			if(st[r+1])return ;
			dfs(l,r+1,(sum^a[r+1]));
		}
	}else{
		for(;l<r;)dfs(l+1,r,sum^a[l]);
	}
	return ;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
		if(a[i]>1)fa=1,fb=1;
		else if(a[i]<1)fa=1;
	}
	if(fa==0){
		cout<<n;
		return 0;
	}
	if(fb==0){
		if(k==1){
			for(int i=1;i<=n;i++)if(a[i])c++;
			cout<<c;
			return 0;
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==0)c++;
				else if(a[i+1]==1)c++,i++;
			}
			cout<<c;
			return 0;
		}
	}
	for(int j=1;j<=n;j++){
		if(st[j])continue;
		dfs(j,j,a[1]);
	}	
	return 0;
}
