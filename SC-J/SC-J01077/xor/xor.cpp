#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005],cnt[500005];
int ou(int x,int y){
	if(x==n){
		return y;
	}
	int ans,ans2;
	if(cnt[x]==0){
		ans=ou(x+1,y);
	}else{
		int cnt1=0;
		for(int i=x-1;i>=1;i--){
			if(cnt[i]!=0){
				cnt1=i;
			}
		}
		if(cnt[cnt1]<x){
			ans=ou(x+1,y+1);
		}else{
			ans=ou(x+1,y);
		}
	}
	ans2=ou(x+1,y);
	return max(ans,ans2);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int ans=a[i];
		for(int j=i;j<=n;j++){
			if(ans==k){
				cnt[i]=j-1;
			}
			ans=ans^a[i];
		}
	}
	cout<<ou(0,1);
	return 0;
}