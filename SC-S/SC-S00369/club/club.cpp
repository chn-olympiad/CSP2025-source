#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Node{
	int a,b,c;
};
int a1[100005],b1[100005],c1[100005];
int mx=0;
int n;
int cnt=0;
int T1;
void dfs(int nw,int sum,int a,int b,int c){
	cnt++;
//	cout<<cnt<<'\n';/
	if(cnt>(420000000ll/T1)){
		return ;
	}
	if(nw==n+1){
		mx=max(mx,sum);
		return ;
	}
	int q=a1[nw],w=b1[nw],e=c1[nw];
	if(q>=w&&w>=e){//qwe abc
		if(a<n/2) dfs(nw+1,(sum+a1[nw]),a+1,b,c);
		if(b<n/2) dfs(nw+1,sum+b1[nw],a,b+1,c);
		if(c<n/2) dfs(nw+1,sum+c1[nw],a,b,c+1);
		return ;
	}
	if(q>=w&&q>=e&&e>=w){//qew acb
		if(a<n/2) dfs(nw+1,(sum+a1[nw]),a+1,b,c);
		if(c<n/2) dfs(nw+1,sum+c1[nw],a,b,c+1);
		if(b<n/2) dfs(nw+1,sum+b1[nw],a,b+1,c);
		return ;
	}
	//wqe bac
	if(b>=a&&b>=c&&a>=c){
		if(b<n/2) dfs(nw+1,sum+b1[nw],a,b+1,c);
		if(a<n/2) dfs(nw+1,(sum+a1[nw]),a+1,b,c);
		if(c<n/2) dfs(nw+1,sum+c1[nw],a,b,c+1);
		return ;
	}
	//weq bca
	if(b>=a&&b>=c&&a<=c){
		if(b<n/2) dfs(nw+1,sum+b1[nw],a,b+1,c);
		if(c<n/2) dfs(nw+1,sum+c1[nw],a,b,c+1);
		if(a<n/2) dfs(nw+1,(sum+a1[nw]),a+1,b,c);
		return ;
	}
	//eqw cab
	if(c>=a&&c>=b&&a>=b){
		if(c<n/2) dfs(nw+1,sum+c1[nw],a,b,c+1);
		if(b<n/2) dfs(nw+1,sum+b1[nw],a,b+1,c);
		if(a<n/2) dfs(nw+1,(sum+a1[nw]),a+1,b,c);
		return ;
	}
	//ewq cba
	
	if(c>=a&&c>=b&&b>=a){
		if(c<n/2) dfs(nw+1,sum+c1[nw],a,b,c+1);
		if(b<n/2) dfs(nw+1,sum+b1[nw],a,b+1,c);
		if(a<n/2) dfs(nw+1,(sum+a1[nw]),a+1,b,c);
		return ;
	}
	if(c<n/2) dfs(nw+1,sum+c1[nw],a,b,c+1);
	if(b<n/2) dfs(nw+1,sum+b1[nw],a,b+1,c);
	if(a<n/2) dfs(nw+1,(sum+a1[nw]),a+1,b,c);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	T1=T;
	while(T--){
		cnt=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>b1[i]>>c1[i];
		}
		dfs(1,0,0,0,0);
		cout<<mx<<'\n';
		mx=0;
	}
	
	return 0;
}