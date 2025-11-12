#include<bits/stdc++.h>
using namespace std;
int t;
int n,r;
int ans;
int a[100005],b[100005],c[100005];
int cmp(int x,int y){
	return x>y;
}
void dfs(int l,int i,int j,int k,int sum){
	if (i>r||j>r||k>r||(i+j+k)>n)return;
	if (l>n&&(i+j+k)==n){
		ans=max(ans,sum);
		return;
	}
	if (i<r){
		dfs(l+1,i+1,j,k,sum+a[l]);
	}
	if (j<r){
		dfs(l+1,i,j+1,k,sum+b[l]);
	}
	if (k<r){
		dfs(l+1,i,j,k+1,sum+c[l]);
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--){
		cin>>n;
		r=n/2;
		ans=0;
		int f=1;
		for (int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if (b[i]!=0||c[i]!=0)f=0;
		}
		if (f){
			sort(a+1,a+1+n,cmp);
			for (int i=1;i<=n/2;i++)ans+=a[i];
			cout<<ans<<endl;
		}else{
			dfs(1,0,0,0,0);
			cout<<ans<<endl;	
		}
	}
	return 0;
}
