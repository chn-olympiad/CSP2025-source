#include<bits/stdc++.h>
#define N 500005
#define ll long long
using namespace std;
struct node{
	int fi,fin,se,sen,dif;
}s[N],p;
int a[N][4];
bool cmp(const node&x,const node&y){
	return x.dif>y.dif;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t;cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			for(int j=1;j<=3;j++)
			if(a[i][j]>=a[i][1]&&a[i][j]>=a[i][2]&&a[i][j]>=a[i][3]) p.fi=j;
			for(int j=1;j<=3;j++)
			if(j!=p.fi&&((a[i][j]>=a[i][1])+(a[i][j]>=a[i][2])+(a[i][j]>=a[i][3]))>=2) p.se=j;
			p.dif=a[i][p.fi]-a[i][p.se];
			p.fin=a[i][p.fi];p.sen=a[i][p.se];
			s[i]=p;
		}
		sort(s+1,s+1+n,cmp);
		int ans=0,cnt[4]={0,0,0,0};
		for(int i=1;i<=n;i++){
			if(cnt[s[i].fi]<n/2) {cnt[s[i].fi]++;ans+=s[i].fin;}
			else {cnt[s[i].se]++;ans+=s[i].sen;}
		}
		cout<<ans<<endl;
	}
	return 0;
}
