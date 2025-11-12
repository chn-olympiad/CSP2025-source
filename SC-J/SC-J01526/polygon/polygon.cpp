#include<bits/stdc++.h>
using namespace std;
long long a[10000];
int n;
long long mmax=0;
unsigned long long fa,q,ans;
int v[9000];
void dfs(int s,int ind){
	if(s>=3&&ans>mmax*2){
		fa++;
	}if(s>n){
		return;
	}for(int i=ind;i<=n;i++){
		if(v[i]!=1){
			v[i]=1;
			ans+=a[i];
			q=mmax;
			mmax=max(mmax,a[i]);
			dfs(s+1,i+1);
			v[i]=0;
			mmax=q;
			ans-=a[i];
		}
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];		
	}
	dfs(0,1);
	cout<<fa%998244353;
	return 0;
} 