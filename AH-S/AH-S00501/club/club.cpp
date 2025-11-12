#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,ans,sum[N];
struct node{
	int a1,a2,a3;
}s[N];
bool cmpA(node a,node b){
	return a.a1>b.a1;
}
bool cmpB(node a,node b){
	return a.a1-a.a2>b.a1-b.a2;
}
bool cmpC(node a,node b){
	if(a.a1!=b.a1) return a.a1>b.a1;
	if(a.a2!=b.a2) return a.a2>b.a2;
	return a.a3>b.a3;
}
void dfs(int idx,int a,int b,int c,int res){
	if(idx>n){
		ans=max(ans,res);
		return ;
	}
	if(res+sum[n]-sum[idx-1]<=ans) return ;
	if(a<n/2) dfs(idx+1,a+1,b,c,res+s[idx].a1);
	if(b<n/2) dfs(idx+1,a,b+1,c,res+s[idx].a2);
	if(c<n/2) dfs(idx+1,a,b,c+1,res+s[idx].a3);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		bool fa=1,fb=1;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].a1>>s[i].a2>>s[i].a3;
			sum[i]=sum[i-1]+(max(s[i].a1,max(s[i].a2,s[i].a3)));
			if(s[i].a2!=0||s[i].a3!=0) fa=0;
			if(s[i].a3!=0) fb=0;
		}
		if(fa){
			sort(s+1,s+n+1,cmpA);
			int ans=0;
			for(int i=1;i<=n/2;i++) ans+=s[i].a1;
			cout<<ans<<endl;
			continue;
		}
		if(fb){
			sort(s+1,s+n+1,cmpB);
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=s[i].a1;
			}
			for(int i=n/2+1;i<=n;i++){
				ans+=s[i].a2;
			}
			cout<<ans<<endl;
			continue;
		}
		if(n==100000){
			sort(s+1,s+n+1,cmpC);
			for(int i=1;i<=n;i++){
				if(s[i].a1>s[i].a2&&s[i].a1>s[i].a3){
					ans+=s[i].a1;
				}
				else if(s[i].a2>s[i].a1&&s[i].a2>s[i].a3){
					ans+=s[i].a2;
				}
				else{
					ans+=s[i].a3;
				}
			}
			cout<<ans<<endl;
			continue;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
