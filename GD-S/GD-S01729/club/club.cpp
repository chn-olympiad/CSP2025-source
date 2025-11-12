#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
long long t,n,Max;
struct node{
	long long a1,a2,a3;
}a[maxn];
void dfs(long long x,long long sum,long long A,long long B,long long C){
	if(x==n+1){
		Max=max(Max,sum);
		return;
	}
	if(A+1<=n/2&&a[x].a1!=0)dfs(x+1,sum+a[x].a1,A+1,B,C);
	if(B+1<=n/2&&a[x].a2!=0)dfs(x+1,sum+a[x].a2,A,B+1,C);
	if(C+1<=n/2&&a[x].a3!=0)dfs(x+1,sum+a[x].a3,A,B,C+1);
}
bool cmp(node aa,node aaa){
	return aa.a1>aaa.a1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i].a1>>a[i].a2>>a[i].a3;
		if(n<=10){
			dfs(1,0,0,0,0);
			cout<<Max<<'\n';
		}else if(n==30){
			for(int i=1;i<=n;i++)Max+=max(max(a[i].a1,a[i].a2),a[i].a3);
			cout<<Max<<'\n';
		}else{
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++)Max+=a[i].a1;
			for(int i=n/2+1;i<=n;i++)Max+=a[i].a2;
			cout<<Max<<'\n';
		}
	}
	return 0;
}
