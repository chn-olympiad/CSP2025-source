#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],b[N],c[N],n;
long long ans;
long long max1(long long a,long long b){
	return a>b?a:b;
}
void dfs(int noww,int an,int bn,int cn,long long ass,int flag){
	if(noww==n+1){
		ans=max1(ans,ass);return;
	}
	if(flag==1)ass+=a[noww];
	else if(flag==2)ass+=b[noww];
	else ass+=c[noww];
	if(an+1<=n/2)dfs(noww+1,an+1,bn,cn,ass,1);
	if(bn+1<=n/2)dfs(noww+1,an,bn+1,cn,ass,2);
	if(cn+1<=n/2)dfs(noww+1,an,bn,cn+1,ass,3);
	return;
}
int max(int a,int b){
	return a>b?a:b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--){
		cin>>n;
		ans=0;bool flag1=1,flag2=1;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0||c[i]!=0)flag1=0;
			if(c[i]!=0)flag2=0;
		}
		if(n==2){
			cout<<max(max(a[1]+b[2],
			max(a[1]+c[2],max(b[1],c[2]))),
			max(a[2]+b[1],max(a[2]+c[1],
			max(b[2],c[1]))))<<'\n';
		}
		else if(flag1){
			sort(a+1,a+1+n);
			for(int i=n;i>=n/2+1;i--)ans+=a[i];
			cout<<ans<<'\n';
		}
		else if(flag2){
			for(int i=2;i<=n;i+=2){
				ans+=max(a[i]+b[i-1],a[i-1]+b[i]);
			}
			cout<<ans<<'\n';
		}
		else{
			dfs(1,1,0,0,0,1);
			dfs(1,0,1,0,0,2);
			dfs(1,0,0,1,0,3);
			cout<<ans<<'\n';
		}
	}
	return 0;
}
