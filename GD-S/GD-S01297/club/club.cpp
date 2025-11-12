#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e5+5;

int T;
int n;
int a[N][4];
int mx[N],sc[N];
int p[4];
vector<int> vec[4];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&T);
	
	while(T--){
		scanf("%d",&n);
		
		for(int i=1;i<=3;i++)
			vec[i].clear(),p[i]=0;
		memset(mx,0,sizeof(mx));
		memset(sc,0,sizeof(sc));
		
		ll maxn=0,ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
				if(a[i][j]>a[i][sc[i]])sc[i]=j;
				if(a[i][sc[i]]>a[i][mx[i]])swap(sc[i],mx[i]);
			}
			vec[mx[i]].push_back(i);
			p[mx[i]]++;
			if(p[mx[i]]>p[maxn])maxn=mx[i];
			ans+=a[i][mx[i]];
		}
		if(p[maxn]>(n>>1)){
			vector<int> t;
			for(int v:vec[maxn])
				t.push_back(a[v][mx[v]]-a[v][sc[v]]);
			sort(t.begin(),t.end());
			for(int i=0;i<p[maxn]-(n>>1);i++)
				ans-=t[i];
		}
		printf("%lld\n",ans);
	} 
	return 0;
}
