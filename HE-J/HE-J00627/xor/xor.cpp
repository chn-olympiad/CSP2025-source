#include<bits/stdc++.h>
using namespace std;
int n,k,ans1=-1;
int a[500010];
void fun(int l,int r,long long sum,int ans){
	if(r>n){
		ans1=max(ans1,ans);
		return;
	}
	sum^=a[r];
	if(sum==k){
		fun(l+r-1,r+1,0,ans+1);
	}else{
		fun(l,r+1,sum,ans);
		fun(l+1,r+1,0,ans);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	fun(1,1,0,0);
	cout<<ans1;
	return 0;
} 
