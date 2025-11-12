#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T,n,a[100005],b[100005],c[100005];
ll suma,sumb,sumc,ans,maxs;
struct stu{
	ll a,b,c;
}s[100005];
ll chg[100005];
bool cmp(int x,int y){
	return chg[x] > chg[y];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		ans = suma = sumb = sumc = 0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&s[i].a,&s[i].b,&s[i].c);
			maxs = max({s[i].a,s[i].b,s[i].c});
			ans += maxs;
			if(maxs == s[i].a){
				suma++;
				chg[i] = s[i].a-max(s[i].b,s[i].c);
				a[suma] = i;
			}
			else if(maxs == s[i].b){
				sumb++;
				chg[i] = s[i].b-max(s[i].a,s[i].c);
				b[sumb] = i;
			}
			else if(maxs == s[i].c){
				sumc++;
				chg[i] = s[i].c-max(s[i].a,s[i].b);
				c[sumc] = i;
			}
		}
		if(suma > n/2){
			sort(a+1,a+suma+1,cmp);
			for(int i=suma;i>=n/2+1;i--)ans -= chg[a[i]];
		}
		else if(sumb > n/2){
			sort(b+1,b+sumb+1,cmp);
			for(int i=sumb;i>=n/2+1;i--)ans -= chg[b[i]];
		}
		else if(sumc > n/2){
			sort(c+1,c+sumc+1,cmp);
			for(int i=sumc;i>=n/2+1;i--)ans -= chg[c[i]];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
