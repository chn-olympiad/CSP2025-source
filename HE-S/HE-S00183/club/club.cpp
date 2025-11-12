#include<bits/stdc++.h>
using namespace std;
const int N=114514;
struct sj{
	int a,b,c;
}p[N];
bool cmp(sj x,sj y){
	return x.a>y.a;
}
long long ans=0,cnt1=0,cnt2=0,cnt3=0,a[N],b[N],c[N],n;
void dfs(int step){
	if(step==n+1){
		long long sum=0;
		for(int i=1;i<=cnt1;i++) sum+=a[i];
		for(int i=1;i<=cnt2;i++) sum+=b[i];
		for(int i=1;i<=cnt3;i++) sum+=c[i];
		ans=max(ans,sum);
		return;
	}
	if(cnt1<n/2){
		a[++cnt1]=p[step].a;
		dfs(step+1);
		cnt1--;
	}
	if(cnt2<n/2){
		b[++cnt2]=p[step].b;
		dfs(step+1);
		cnt2--;
	}
	if(cnt3<n/2){
		c[++cnt3]=p[step].c;
		dfs(step+1);
		cnt3--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		bool bf=1;
		ans=0,cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
			if(p[i].b!=0 or p[i].c!=0){
				bf=0;
			}
		}
		if(bf==1){
			sort(p+1,p+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=p[i].a;
			}
			cout<<ans<<'\n';
			continue;
		}
		else{
			dfs(1);
			cout<<ans<<'\n';
		}
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
