#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define debug(a) cout<<#a<<"="<<a<<"\n";
using namespace std;
const long long N=2e5+7,N2=3e6+7,M=1e9+7,M2=998244353,B=133;
long long n,m,p[N2],p2[N2],sum[N],sum2[N];
struct node{
	string a,b;
	long long s1,s2,s3,s4;
};
node c[N];
long long check(long long l,long long r){
	if(l>r) return 0;
	return (sum[r]-sum[l-1]*p[r-l+1]%M+M)%M;
}
long long check2(long long l,long long r){
	if(l>r) return 0;
	return (sum2[r]-sum2[l-1]*p2[r-l+1]%M2+M2)%M2;
}
bool cmp(node x,node y){
	return x.a.size()<y.a.size();
}
long long mii(long long x){
	int l=1,r=n+1;
	while(l<r){
		int mid=(l+r)/2;
		if(c[mid].a.size()>=x) r=mid;
		else l=mid+1;	
	}
	return l;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	p[0]=p2[0]=1;
	rep(i,1,3e6) p[i]=p[i-1]*B%M;
	rep(i,1,3e6) p2[i]=p2[i-1]*B%M2;
	cin>>n>>m;
	rep(i,1,n){
		cin>>c[i].a>>c[i].b;
		c[i].s1=c[i].s2=0;
		rep(j,1,c[i].a.size()){
			c[i].s1=(c[i].s1*B+(c[i].a[j-1]-'a'+1))%M;
			c[i].s2=(c[i].s2*B+(c[i].b[j-1]-'a'+1))%M;
			c[i].s3=(c[i].s3*B+(c[i].a[j-1]-'a'+1))%M2;
			c[i].s4=(c[i].s4*B+(c[i].b[j-1]-'a'+1))%M2;
		}
	}
	sort(c+1,c+1+n,cmp);
	rep(i,1,m){
		string c1,c2;
		cin>>c1>>c2;
		long long s=0,s2=0,ans=0,ml=0,mr=0;
		rep(j,1,c1.size()){
			sum[j]=(sum[j-1]*B+(c1[j-1]-'a'+1))%M;
			sum2[j]=(sum2[j-1]*B+(c1[j-1]-'a'+1))%M2;
			s=(s*B+(c2[j-1]-'a'+1))%M;
			s2=(s2*B+(c2[j-1]-'a'+1))%M2;
			if(c1[j-1]!=c2[j-1]){
				if(ml==0) ml=j;
				mr=j;
			}
		}
		long long id=mii(mr-ml+1);
		rep(j,id,n){
			rep(l,max(1ll,mr-(long long)c[j].a.size()+1),c1.size()-c[j].a.size()+1){
				long long r=l+c[j].a.size()-1;
				if(check(l,r)==c[j].s1&&(sum[l-1]*p[c1.size()-l+1]%M+c[j].s2*p[c1.size()-r]%M+check(r+1,c1.size()))%M==s){
				if(check2(l,r)==c[j].s3&&(sum2[l-1]*p2[c1.size()-l+1]%M2+c[j].s4*p2[c1.size()-r]%M2+check2(r+1,c1.size()))%M2==s2){
					ans++;
				}
				}
			}
		}
		cout<<ans<<"\n";
	}
    return 0;
}
