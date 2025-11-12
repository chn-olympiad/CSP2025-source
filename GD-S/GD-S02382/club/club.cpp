#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N = 1e5+5;
int t,n,cnt[3],a[3],w,ans,c[3][N];
int find(){
	int x=max(a[0],max(a[1],a[2]));
	for(int i=0;i<3;i++)if(x==a[i])return i;
	return 0;
}
void solve(int x){
	if(cnt[x]<=n/2)return;
	sort(c[x]+1,c[x]+cnt[x]+1);
	for(int i=1;i<=cnt[x]-n/2;i++)ans-=c[x][i];
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
	while(t--){
		cin>>n;cnt[0]=cnt[1]=cnt[2]=0;ans=0;
		for(int T=1;T<=n;T++){
			for(int i=0;i<3;i++)cin>>a[i];
			w=find();
			ans+=a[w];
			c[w][++cnt[w]]=min(a[w]-a[(w+1)%3],a[w]-a[(w+2)%3]);
		}
		for(int i=0;i<3;i++)solve(i);
		cout<<ans<<'\n';
	}
	return 0;
}
