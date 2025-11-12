#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long T,n,m,ans;
bool flag1,flag2;
struct Node{
	int id;
	long long a1,a2,a3;
}a[N];
void dfs(int cnt1,int cnt2,int cnt3,long long sum,int k){
	if(k>n){
		ans=max(ans,sum);
		return;
	}
	if(cnt1<m)dfs(cnt1+1,cnt2,cnt3,sum+a[k].a1,k+1);
	if(cnt2<m)dfs(cnt1,cnt2+1,cnt3,sum+a[k].a2,k+1);
	if(cnt3<m)dfs(cnt1,cnt2,cnt3+1,sum+a[k].a3,k+1);
}
void dfss(int cnt1,int cnt2,long long sum,int k){
	if(k>n){
		ans=max(ans,sum);
		return;
	}
	if(cnt1<m)dfss(cnt1+1,cnt2,sum+a[k].a1,k+1);
	if(cnt2<m)dfss(cnt1,cnt2+1,sum+a[k].a2,k+1);
}
bool cmp(Node a,Node b){
	return a.a1>b.a1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		ans=0;flag1=flag2=1;
		cin>>n;m=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(flag2&&a[i].a3!=0)flag2=0;
			if(flag1&&(a[i].a2!=0||a[i].a3!=0))flag1=0; 
		}
		if(flag1){
			sort(a+1,a+1+n,cmp);
			for(int i=n;i>=m;i--)ans+=a[i].a1;
		}
		else if(flag2)
			dfss(0,0,0,1);
		else
			dfs(0,0,0,0,1);
		cout<<ans<<"\n";
	}
	return 0;
}
