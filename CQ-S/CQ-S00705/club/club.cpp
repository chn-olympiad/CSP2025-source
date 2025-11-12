#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int T,n,a[N][5],tot,ans,s[5];
struct node{
	int val,id;
}b[N];
bool cmp(node a,node b){
	return a.val<b.val;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		s[1]=s[2]=s[3]=0;
		memset(b,0x3f,sizeof b);
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int now,nmax=0;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(nmax<a[i][j])
				nmax=a[i][j],now=j;
			}
			b[i].id=now;
			s[now]++;
			ans+=nmax;
			for(int j=1;j<=3;j++){
				if(now==j) continue;
				b[i].val=min(b[i].val,nmax-a[i][j]);
			}
		}
		sort(b+1,b+1+n,cmp);
		int maxn=0,maxg;
		for(int i=1;i<=3;i++){
			if(maxn<s[i]) maxn=s[i],maxg=i;
		}
		int cnt=max(maxn-n/2,0ll);
		int kkk=0;
		while(cnt){
			kkk++;
			if(b[kkk].id==maxg) ans-=b[kkk].val,cnt--;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
