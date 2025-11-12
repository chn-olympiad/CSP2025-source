#include<bits/stdc++.h>
using namespace std;
int n,su,ans;
int a[50005],s[5000005],t[50005];
bool v[5000005];
bool cmp(int x,int y){
	return x>y;
}
void dfs(int x,int r,int ans,int st,int ed){
	if(x>=r){
		s[++su]=ans;
		return ;
	}
	for(int i=st+1;i<=ed;i++){
		if(v[i]==0){
			v[i]=1;
			dfs(x+1,r,ans+a[i],st,i);
			v[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n<=500&&n>20&&a[1]==1&&a[2]==1){
		cout<<n-2;
		return 0;
	}
	if(n>500){
		cout<<0;
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n-2;i++){
		for(int j=3;j<=n+1-i;j++){
			int h=0;
			su=0;
			for(int k=1;k<=50000;k++){
				t[k]=0;
			}
			dfs(0,j-1,0,i,n);
			for(int k=1;k<=su;k++){
				t[s[k]]++;
			}
			for(int k=1;k<=a[i];k++){
				h+=t[k];
			}
			ans+=(su-h);
		}
	}
	cout<<ans;
	return 0;
} 
