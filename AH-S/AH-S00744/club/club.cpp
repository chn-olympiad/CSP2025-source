#include<bits/stdc++.h>
using namespace std;
int n,ans[4],cnt[4],maxa=-1;
struct mamyi{
	int a,b,c,d;
}x[100005];
void dfs(int k){
	if(k>n){
		maxa=max(maxa,ans[1]+ans[2]+ans[3]);
		return;
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]==n/2) continue;
		if(i==1) ans[1]+=x[k].a,cnt[1]++;
		if(i==2) ans[2]+=x[k].b,cnt[2]++;
		if(i==3) ans[3]+=x[k].c,cnt[3]++;
		dfs(k+1);
		if(i==1) ans[1]-=x[k].a,cnt[1]--;
		if(i==2) ans[2]-=x[k].b,cnt[2]--;
		if(i==3) ans[3]-=x[k].c,cnt[3]--;
	}
}
bool cmp(mamyi f,mamyi j){
	return f.b>j.b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		ans[1]=ans[2]=ans[3]=cnt[1]=cnt[2]=cnt[3]=0;
		maxa=-1;
		cin>>n;
		bool aa=1;
		for(int i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
			if(x[i].a!=0||x[i].c!=0) aa=0;
		}
		if(aa){
			sort(x+1,x+n+1,cmp);
			long long sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=x[i].b;
			}
			cout<<sum<<"\n";
			continue;
		}
		dfs(1);
		cout<<maxa<<"\n";
	}
	return 0;
}
