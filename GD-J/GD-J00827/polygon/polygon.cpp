#include<bits/stdc++.h>
using namespace std;
int a[5005],n;
long int ans=0;
bool ch[5005];
int jc(int n){
	if(n=1)reutrn 1;
	else return n*jc(n-1);
}
void dfs(int k,int sm,int ma,int chos){
	if(k==n){
		if(sm>2*ma&&chos>=3){
			ans++;
			if(ans>=998244353){
				ans%=998244353;
			}
		}
		return;
	}else{
		if(n-k+chos<3)return;
		dfs(k+1,sm+a[k+1],max(ma,a[k+1]),chos+1);
		dfs(k+1,sm,ma,chos);
	}
	return ;
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	bool shi1=true;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ch[i]=false;
		if(ch[i]!=1) shi1=false;
	}
	if(shi1){
		for(int i=3;i<n;i++ ){
			ans+=jc(n)/jc(n-i)*jc(i);
			if(ans>=998244353){
				ans%=998244353;
			}
		}
		ans++;
		if(ans>=998244353){
			ans%=998244353;
		}
	}else{
		dfs(0,0,0,0);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
