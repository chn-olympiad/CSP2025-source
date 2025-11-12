#include<bits/stdc++.h>
using namespace std;
int t;
int n;
struct node{
	int a,b,c;
}a[100001];
bool cmp(node a,node b){
	return a.a>b.a;
}
bool cmp2(node a,node b){
	return a.b>b.b;
}
bool cmp3(node a,node b){
	return a.c>b.c;
}
int ans;
void dfs(int step,int cnt1,int cnt2,int cnt3,int sum){
	if(step>n){
		ans=max(ans,sum);
		return;
	}
	if(cnt1<n/2) dfs(step+1,cnt1+1,cnt2,cnt3,sum+a[step].a);
	if(cnt2<n/2) dfs(step+1,cnt1,cnt2+1,cnt3,sum+a[step].b);
	if(cnt3<n/2) dfs(step+1,cnt1,cnt2,cnt3+1,sum+a[step].c);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int flag=1,flag2=1,flag3=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].b!=0 || a[i].c!=0) flag=0;
			if(a[i].a!=0 || a[i].c!=0) flag2=0;
			if(a[i].b!=0 || a[i].a!=0) flag3=0;
		}
		if(flag){
			sort(a+1,a+1+n,cmp);
			int sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=a[i].a;
			}
			cout<<sum<<endl;
		}else if(flag2){
			sort(a+1,a+1+n,cmp2);
			int sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=a[i].b;
			}
			cout<<sum<<endl;
		}else if(flag3){
			sort(a+1,a+1+n,cmp3);
			int sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=a[i].c;
			}
			cout<<sum<<endl;
		}else {
			ans=0;
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
		}
	}
	return 0;
}
