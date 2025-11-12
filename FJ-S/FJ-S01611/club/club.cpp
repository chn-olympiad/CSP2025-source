#include<iostream>
#include<cstdio>
#include<algorithm>
#define mn 100006
using namespace std;
long long n,a[mn],b[mn],c[mn],sz[5],ans,t,f[5][mn];
bool cmp(long long u,long long v){
	return u>v;
}
void wrk(){
	scanf("%lld",&n);
	ans=0;
	sz[1]=sz[2]=sz[3]=0;
	for(int i=1;i<=n;i++){
		scanf("%lld %lld %lld",&a[i],&b[i],&c[i]);
		if(a[i]>=b[i]&&a[i]>=c[i]){
			sz[1]++;
			f[1][sz[1]]=a[i]-(b[i]>=c[i]?b[i]:c[i]);
			ans+=a[i];
		}else if(b[i]>=c[i]){
			sz[2]++;
			f[2][sz[2]]=b[i]-(a[i]>=c[i]?a[i]:c[i]);
			ans+=b[i]; 
		}else{
			sz[3]++;
			f[3][sz[3]]=c[i]-(b[i]>=a[i]?b[i]:a[i]);
			ans+=c[i];
		}
	}
	sort(f[1]+1,f[1]+sz[1]+1,cmp);
	sort(f[2]+1,f[2]+sz[2]+1,cmp);
	sort(f[3]+1,f[3]+sz[3]+1,cmp);
	if(sz[1]>(n/2)){
		for(int i=n/2+1;i<=sz[1];i++){
			ans-=f[1][i];
		}
	}else if(sz[2]>(n/2)){
		for(int i=n/2+1;i<=sz[2];i++){
			ans-=f[2][i];
		}
	}else if(sz[3]>(n/2)){
		for(int i=n/2+1;i<=sz[3];i++){
			ans-=f[3][i];
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int rp=1;rp<=t;rp++) wrk();
	return 0;
}
