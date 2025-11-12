#include<bits/stdc++.h>
using namespace std;
const int N=1e5+15;
int a[N],b[N],c[N];
int ans;
int n;
void dfs(int i,int s1,int s2,int s3,int sum){
	if(i>n){
		ans=max(ans,sum);
		return ;
	}
	if(s1<n/2){
		dfs(i+1,s1+1,s2,s3,sum+a[i]);
	}
	if(s2<n/2){
		dfs(i+1,s1,s2+1,s3,sum+b[i]);
	}
	if(s3<n/2){
		dfs(i+1,s1,s2,s3+1,sum+c[i]);
	}
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
		ans=INT_MIN;
	}
	return 0;
} 
