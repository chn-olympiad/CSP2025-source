#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,a1[N],a2[N],a3[N];
long long ans,sum1,sum2,sum3;
bool cmp(int x,int y){
	return x>y;
}
void dfs(int now,int cnt1,int cnt2,int cnt3,long long sum){
	if(now==n+1)ans=max(ans,sum);
	if(cnt1<n/2)dfs(now+1,cnt1+1,cnt2,cnt3,sum+a1[now]);
	if(cnt2<n/2)dfs(now+1,cnt1,cnt2+1,cnt3,sum+a2[now]);
	if(cnt3<n/2)dfs(now+1,cnt1,cnt2,cnt3+1,sum+a3[now]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;sum1=0;sum2=0;sum3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			sum1+=a1[i];sum2+=a2[i];sum3+=a3[i];
		}
		if(sum2+sum3==0){
			sort(a1+1,a1+1+n,cmp);
			for(int i=1;i<=n/2;i++)ans+=a1[i];
			cout<<ans<<endl;
			return 0;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
}
