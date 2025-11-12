#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
int t,n;
struct P{
	int a,b,c;
	ll sum;
	int cha;
	int mx,mi,md;
	int ma,mn,z;
}p[100050];
int marx(int a,int b,int c){
	return max(a,max(b,c));
}
int mirn(int a,int b,int c){
	return min(a,min(b,c));
}
bool operator<(P a,P b){
	if(a.cha!=b.cha){
	return a.cha>b.cha;
	}
	if(a.cha==b.cha){
		return a.sum<b.sum;
	}
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ll ans=0;
		cin>>n;
		memset(p,0,sizeof(p));
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
			p[i].sum=p[i].a+p[i].b+p[i].c;
			p[i].cha=marx(p[i].a,p[i].b,p[i].c)-mirn(p[i].a,p[i].b,p[i].c);
			p[i].z=p[i].sum-marx(p[i].a,p[i].b,p[i].c)-mirn(p[i].a,p[i].b,p[i].c);
			p[i].cha+=marx(p[i].a,p[i].b,p[i].c)-p[i].z;
			if(p[i].a==marx(p[i].a,p[i].b,p[i].c)){
				p[i].mx=1;p[i].ma=p[i].a;
			}
			if(p[i].b==marx(p[i].a,p[i].b,p[i].c)){
				p[i].mx=2;p[i].ma=p[i].b;
			}
			if(p[i].c==marx(p[i].a,p[i].b,p[i].c)){
				p[i].mx=3;p[i].ma=p[i].c;
			}
			if(p[i].a==mirn(p[i].a,p[i].b,p[i].c)){
				p[i].mi=1;p[i].mi=p[i].a;
			}
			if(p[i].b==mirn(p[i].a,p[i].b,p[i].c)){
				p[i].mi=2;p[i].mi=p[i].b;
			}
			if(p[i].c==mirn(p[i].a,p[i].b,p[i].c)){
				p[i].mi=3;p[i].mi=p[i].c;
			}
			p[i].md=6-p[i].mi-p[i].mx;
		}
		sort(p+1,p+1+n);
		int ca[100000],cb[100000],cc[100000],ta=0,tb=0,tc=0;
		for(int i=1;i<=n;i++){
			if(p[i].mx==1){
				ca[++ta]=p[i].a;
			}
			if(p[i].mx==2){
				cb[++tb]=p[i].b;
			}
			if(p[i].mx==3){
				cc[++tc]=p[i].c;
			}
		}
		sort(ca+1,ca+1+n,cmp);
		sort(cb+1,cb+1+n,cmp);
		sort(cc+1,cc+1+n,cmp);
		for(int i=n/2+1;i<=marx(ta,tb,tc);i++){
			ca[i]=0;
			cb[i]=0;
			cc[i]=0;
		}
		//key搞不出来，测评机放过我 
		for(int i=1;i<=n/2;i++){
			ans+=ca[i]+cb[i]+cc[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
