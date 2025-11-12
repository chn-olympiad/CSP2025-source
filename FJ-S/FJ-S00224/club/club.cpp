#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,t,t1,t2,n;ll ans;
struct kun{int a[4];}d[100110];
bool cmp(kun o,kun oo){return o.a[t]-max(o.a[t1],o.a[t2])<oo.a[t]-max(oo.a[t1],oo.a[t2]);}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){cin>>n;ans=0;vector<kun>s[4];
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&d[i].a[1],&d[i].a[2],&d[i].a[3]);
			if(d[i].a[1]>=d[i].a[2]&&d[i].a[1]>=d[i].a[3])s[1].push_back(d[i]);
			if(d[i].a[2]>d[i].a[1]&&d[i].a[2]>=d[i].a[3])s[2].push_back(d[i]);
			if(d[i].a[3]>d[i].a[2]&&d[i].a[3]>d[i].a[1])s[3].push_back(d[i]);
		}for(int i=1;i<=3;i++){
			for(int j=0;j<s[i].size();j++){
				ans+=s[i][j].a[i];
			}
		}//cout<<ans<<"\n";
		if(s[1].size()<=n/2&&s[2].size()<=n/2&&s[3].size()<=n/2)cout<<ans<<"\n";
		else{
			for(int i=1;i<=3;i++)if(s[i].size()>n/2){t=i;break;}
			if(t==1)t1=2,t2=3;
			if(t==2)t1=1,t2=3;
			if(t==3)t1=1,t2=2;
			sort(s[t].begin(),s[t].end(),cmp);
			//for(int i=0;i<s[t].size()-n/2;i++)cout<<s[t][i].a[1]<<' '<<s[t][i].a[2]<<' '<<s[t][i].a[3]<<"\n";cout<<"\n";
			for(int i=0;i<s[t].size()-n/2;i++){
				ans-=(s[t][i].a[t]-max(s[t][i].a[t1],s[t][i].a[t2]));
			}cout<<ans<<"\n";
		}	
	}
	return 0;
}