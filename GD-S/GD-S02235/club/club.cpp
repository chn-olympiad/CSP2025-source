#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int a[N],i,j,n,m,dp[N][4],b[N],c[N],t;
int z1,z2,z3;
bool ch,bh;
long long an,ans[N];
void dfs(int s,int d){
	if(n<s) return;
	if(d==1) ans[s]=a[s]+ans[s-1];
	if(d==2) ans[s]=b[s]+ans[s-1];
	if(d==3) ans[s]=c[s]+ans[s-1];
	if(s==n){
		an=max(an,ans[s]);
		return;
	} 
	if(z1<n/2){
		z1++;
		dfs(s+1,1);
		z1--;
	}
	if(z2<n/2){
		z2++;
		dfs(s+1,2);
		z2--;
	}
	if(z3<n/2&&!bh){
		z3++;
		dfs(s+1,3);
		z3--;
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ch=bh=true;
		an=0;
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(c[i]!=0||b[i]!=0) ch=false;
			if(c[i]!=0) bh=false; 
		} 
		if(ch){
			sort(a+1,a+1+n);
			for(i=n;i>=n;i++) an+=a[i];
			cout<<an<<endl;
			continue;
		}
		z1=z2=z3=0;
		memset(ans,0,sizeof(ans));
		z1=1;
		dfs(1,1);
		z1=0,z2=1;
		dfs(1,2);
		z2=0,z3=1;
		if(!bh)dfs(1,3);
		cout<<an<<endl;
	}
	fclose(stdin);
	return 0;
}
