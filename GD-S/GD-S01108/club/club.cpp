#include<bits/stdc++.h>
using namespace std;
int t,n,ans,a[500005][5];
struct tt{
	int a,b,c;
}b[500005]; 
bool cmp(tt x,tt y){
	return x.a>y.a;
}
void dfs(int d,int s1,int s2,int s3,int s){
	if(d==n+1){
		ans=max(ans,s);
		return;
	}
	if(s1+1<=n/2){
		dfs(d+1,s1+1,s2,s3,s+a[d][1]);
	}
	if(s2+1<=n/2){
		dfs(d+1,s1,s2+1,s3,s+a[d][2]);
	}
	if(s3+1<=n/2){
		dfs(d+1,s1,s2,s3+1,s+a[d][3]);
	}
	return;
}
void work(){
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
		b[i].a=a[i][1];
		b[i].b=a[i][2];
		b[i].c=a[i][3];
	}
	sort(b+1,b+n+1,cmp);
	if(n<=30) dfs(1,0,0,0,0);
	else{
		for(int i=1;i<=n/2;i++){
			ans+=b[i].a;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t; 
	while(t--){
		work();
	}
	return 0;
} 
