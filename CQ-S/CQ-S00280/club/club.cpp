#include<bits/stdc++.h>
using namespace std;
int aaaaa;
long long n,m,k,l,T,c1[1000007],c2[1000007],c3[1000007],cx[1000007],ct[1000007],ans,s1,s2,s3,ss,sn,b[1000007],js;
int bbbbb;
int main(){
	//cerr<<(double)(&aaaaa-&bbbbb)/6e7*256<<'\n';
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int u=1;u<=T;u++){
		scanf("%lld",&n);js=ans=s1=s2=s3=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&c1[i],&c2[i],&c3[i]);	
			long long ma=max({c1[i],c2[i],c3[i]}),mi=min({c1[i],c2[i],c3[i]}),mz=c1[i]+c2[i]+c3[i]-ma-mi;
			ans+=ma;
			if(ma==c1[i])++s1,cx[i]=1;
			else if(ma==c2[i])++s2,cx[i]=2;
			else ++s3,cx[i]=3;
			ct[i]=ma-mz;
		}
		ss=max({s1,s2,s3});
		if(ss<=n/2){
			printf("%lld\n",ans);
			continue;
		}
		sn=(ss==s1?1:ss==s2?2:3);
		for(int i=1;i<=n;i++)if(sn==cx[i])b[++js]=ct[i];
		sort(b+1,b+js+1);reverse(b+1,b+js+1);
		while(ss>(n>>1)){
			ss--;
			ans-=b[js];
			js--;
		} 
		printf("%lld\n",ans);
	}
}
