#include<bits/stdc++.h>
using namespace std;
long long n,k,anss;
long long a[500005];
void dfs(long long p,long long lastp,long long ans){
	if(p>n){
		if(lastp==k){
			anss=max(anss,ans);
		}
		return ;
	}
	if(lastp==k){
		if(a[p]==k) ans++; 
		dfs(p+1,a[p],ans);
		if(a[p]==k) ans--;
		
		dfs(p+1,lastp,ans);
	}else{
		if((long long)(lastp^a[p])==k){
			ans++;
		} 
		dfs(p+1,(long long)(lastp^a[p]),ans);
		if((long long)(lastp^a[p])==k) ans--;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flagA=1,flagB=1;
	int cnt1=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) cnt1++;
		if(a[i]!=0) flagA=0;
		if(a[i]>1) flagB=0;
	}
	if(flagA){
		if(k==0) cout<<n<<endl;
		else cout<<0<<endl;
		return 0;
	}
	if(flagB){
		if(k==1) cout<<cnt1<<endl;
		else if(k==0){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
				else if(a[i]==1&&a[i+1]==1){
					ans++;
					i=i+1;
				}
				
			}
			cout<<ans<<endl;
		}else{
			cout<<0<<endl;
		}
		return 0;
	}
	anss=0;
	dfs(1,k,0);
	cout<<anss<<endl;
	return 0;
}

