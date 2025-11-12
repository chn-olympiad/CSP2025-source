#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],s,ans=0,flag3=0;
bool vis[500001],flag=0,flag2=0;
bool f(int l,int r){
	if(l>r) s=l,l=r,r=s;
	if(vis[l]) return 0;
	s=a[l];
	for(int i=l+1;i<=r;i++){
		if(vis[i]) return 0;
		s^=a[i];
	}
	if(s==k) return 1;
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[i]=0;
		if(a[i]==1) flag3++;
		else flag=1;
		if(a[i]!=1&&a[i]!=0) flag2=1;
	}
	if(!flag){
		cout<<n/2;
		return 0;
	}
	if(!flag2){
		if(k) cout<<flag3;
		else cout<<flag3/2+(n-flag3)/2;
		return 0;
	}
	for(int l=1;l<=n;l++){
		for(int r=n;r>=1;r--){
			if(f(l,r)){
				ans++;
				for(int i=l;i<=r;i++)
					vis[i]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
