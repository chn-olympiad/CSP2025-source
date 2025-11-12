#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=100010;
int t,n,lim,p,s[N],co[N];
LL ans,a[N][5];
multiset<LL> st;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans=0,st.clear();
		s[1]=s[2]=s[3]=0,lim=n/2;
		for(int i=1;i<=n;i++){
			co[i]=0;
			for(int j=1;j<=3;j++){
				scanf("%lld",&a[i][j]);
			}
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				ans+=a[i][1],co[i]=1,s[1]++;
			}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				ans+=a[i][2],co[i]=2,s[2]++;
			}else{
				ans+=a[i][3],co[i]=3,s[3]++;
			}
		}
		if(s[1]<=lim&&s[2]<=lim&&s[3]<=lim){
			printf("%lld\n",ans);
			continue;
		}
		for(int i=1;i<=n;i++){
			if(s[co[i]]<=lim)continue;
			if(co[i]==1)st.insert(min(a[i][1]-a[i][2],a[i][1]-a[i][3]));
			if(co[i]==2)st.insert(min(a[i][2]-a[i][1],a[i][2]-a[i][3]));
			if(co[i]==3)st.insert(min(a[i][3]-a[i][1],a[i][3]-a[i][2]));
		}
		if(s[1]>lim)p=1;
		if(s[2]>lim)p=2;
		if(s[3]>lim)p=3;
		for(int i=s[p];i>lim;i--){
			ans-=*st.begin();
			st.erase(st.begin());
		}
		printf("%lld\n",ans);
	} 
	return 0;
}
