#include<bits/stdc++.h>
using namespace std;
int T;
int n;
struct box{
	int f,s,t;
};
box a[100005];
long long ans;
void dfs(int now,int fi,int se,int th,long long z){
	if(now>n){
		ans=max(ans,z);
		return;
	}
	if(fi<n/2){
		dfs(now+1,fi+1,se,th,z+a[now].f);
	}
	if(se<n/2){
		dfs(now+1,fi,se+1,th,z+a[now].s);
	}
	if(th<n/2){
		dfs(now+1,fi,se,th+1,z+a[now].t);
	}
	return;
}
bool cmp(box a,box b){
	return a.f>b.f;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		bool pan=0,pan1=0;
		for(int i=1;i<=n;++i){
			cin>>a[i].f>>a[i].s>>a[i].t;
			if(a[i].s!=0)pan=1;
			if(a[i].t=0)pan1!=0;
		}
		if(!pan&&!pan1){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;++i){
				ans+=a[i].f;
			}
			cout<<ans;
			continue;
		}
		dfs(1,0,0,0,(long long)0);
		cout<<ans<<endl;
	}
	return 0;
}
