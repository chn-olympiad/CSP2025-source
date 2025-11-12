#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int yi[N],er[N],sa[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--){
		int n,ha=0,hb=0,hc=0,ans=0;
		scanf("%d",&n);
		for(int i=1; i<=n; i++){
			int a,b,c,jl1,jl2;
			scanf("%d%d%d",&a,&b,&c);
			if(a>=b){
				if(c>a)jl1=3,jl2=a;
				else if(c<=b)jl1=1,jl2=b;
				else jl1=1,jl2=c;
			}
			else {
				if(c>b)jl1=3,jl2=b;
				else if(c<=a)jl1=2,jl2=a;
				else jl1=2,jl2=c;
			}
			if(jl1==1)yi[++ha]=a-jl2,ans+=a;
			if(jl1==2)er[++hb]=b-jl2,ans+=b;
			if(jl1==3)sa[++hc]=c-jl2,ans+=c;
		}
		int p=0;n/=2;
		if(ha>n)sort(yi+1,yi+1+ha),p=1;
		if(hb>n)sort(er+1,er+1+hb),p=2;
		if(hc>n)sort(sa+1,sa+1+hc),p=3;
		if(p==1)for(int i=1; i<=ha-n; i++)ans-=yi[i];
		if(p==2)for(int i=1; i<=hb-n; i++)ans-=er[i];
		if(p==3)for(int i=1; i<=hc-n; i++)ans-=sa[i];
		printf("%d\n",ans);
	}
	return 0;
}
