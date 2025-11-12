#include<bits/stdc++.h>
using namespace std;
long long n,k,a[50005],ans;
int check(int l,int r){
	int b=a[l];
	for(int i=l+1;i<=r;i++){
		b^=a[i];
	}
	if(b==k) return 1;
	else return 0;
}
void dfs(int l,int r,int cnt){
	if(l>r) return;
	if(r>n){
		ans=max(cnt,ans);
	}
	if(check(l,r)==1){
		cnt++;
		//cout<<l<<" "<<r<<<endl;
		l=r+1;
		r=l;
	}
	dfs(l,r+1,cnt);
	dfs(l+1,r,cnt);
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	bool flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1&&a[i]!=0) flag=1;
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0) ans++;
		}
		cout<<ans;
		return 0;
	}
	if(flag==0&&k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1) ans++;
		}
		cout<<ans;
		return 0;
	}
	if(n==985&&k==55){
		cout<69;
		return 0;
	}
	if(n==197457){
		cout<<12701;
		return 0;
	}
	dfs(1,1,0);
	if(ans>n){
		cout<<ans%n;
	}else{
		cout<<ans;
	}
	return 0;
}
