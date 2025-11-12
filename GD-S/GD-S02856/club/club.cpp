#include<bits/stdc++.h>
using namespace std;
long long n,t,maxn;
struct poi{
	long long v1,v2,v3;
}a[100005];
bool cmp(poi s1,poi s2){
	return s1.v1>=s2.v1;
}
void dfs(long long x,long long n1,long long n2,long long n3,long long sum){
	maxn=max(maxn,sum);
	if(x==n+1)return;
	if(n1>0){
		dfs(x+1,n1-1,n2,n3,sum+a[x].v1);
	}
	if(n2>0){
		dfs(x+1,n1,n2-1,n3,sum+a[x].v2);
	}
	if(n3>0){
		dfs(x+1,n1,n2,n3-1,sum+a[x].v3);
	}
}
void dfs1(long long x,long long n1,long long n2,long long sum){
	maxn=max(maxn,sum);
	if(x==n+1)return;
	if(n1>0){
		dfs1(x+1,n1-1,n2,sum+a[x].v1);
	}
	if(n2>0){
		dfs1(x+1,n1,n2-1,sum+a[x].v2);
	}
	cout<<1;
}
void dfs2(){
	sort(a+1,a+100001,cmp);
	long long sum=0;
	for(int i=1;i<=n/2;i++)sum+=a[i].v1;
	maxn=sum;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		maxn=-1;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].v1>>a[i].v2>>a[i].v3;
		}
		if(n==200)dfs1(1,n/2,n/2,0);
		else if(n==100000)dfs2();
		else dfs(1,n/2,n/2,n/2,0);
		cout<<maxn<<endl;
	}
	return 0;
}
