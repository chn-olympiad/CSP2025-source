#include<bits/stdc++.h>
using namespace std;
long long a[100005][3],mao=0;
void dfs(long long r,long long n,int q,int b,int c,long long ans){
	if(q>n/2||b>n/2||c>n/2){
		
		ans=0;
		return;
	}
	if(r>=n&&ans>mao){
		mao=ans;
		return ;
	}
	if(r>=n){
		return ;
	}
	ans=ans+a[r][0];q++;
	dfs(r+1,n,q,b,c,ans);
	ans-=a[r][0];q--;
	ans+=a[r][1];b++;
	dfs(r+1,n,q,b,c,ans);
	ans-=a[r][1];b--;
	ans+=a[r][2];c++;
	dfs(r+1,n,q,b,c,ans);
	ans-=a[r][2];c--;
	return ;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		dfs(0,n,0,0,0,0);
		cout<<mao<<endl;
		mao=0;
	}
	return 0;
}
