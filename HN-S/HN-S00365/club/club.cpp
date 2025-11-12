#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
struct node{
	long long a,b,c;
	long long fi,se,th;
	long long xfi,xse,xth;
	long long flag,cha;
}v[100100];
long long T,n,a,b,c,f[100100],s[100100],t[100100];
void pdd(long long i,long long a,long long b,long long c){
	if(a>=b){
		if(b>=c) v[i].fi=1,v[i].se=2,v[i].th=3,v[i].xfi=a,v[i].xse=b,v[i].xth=c;
		else if(a>=c) v[i].fi=1,v[i].se=3,v[i].th=2,v[i].xfi=a,v[i].xse=c,v[i].xth=b;
		else v[i].fi=3,v[i].se=1,v[i].th=2,v[i].xfi=c,v[i].xse=a,v[i].xth=b;
	}
	else{
		if(a>=c) v[i].fi=2,v[i].se=1,v[i].th=3,v[i].xfi=b,v[i].xse=a,v[i].xth=c;
		else if(b>=c) v[i].fi=2,v[i].se=3,v[i].th=1,v[i].xfi=b,v[i].xse=c,v[i].xth=a;
		else v[i].fi=3,v[i].se=2,v[i].th=1,v[i].xfi=c,v[i].xse=b,v[i].xth=a;
	}
	v[i].cha=v[i].xfi-v[i].xse;
	return;
}
long long cmp(node x,node y){
	return x.cha>y.cha;
}
long long cmp1(node x,node y){
	if(x.a!=y.a) return x.a>y.a;
	else{
		if(x.b!=y.b) return x.b<y.b;
		else return x.c<y.c;
	}
}
long long cmp2(node x,node y){
	if(x.b!=y.b) return x.b>y.b;
	else{
		if(x.a!=y.a) return x.a<y.a;
		else return x.c<y.c;
	}
}
long long cmp3(node x,node y){
	if(x.c!=y.c) return x.c>y.c;
	else{
		if(x.a!=y.a) return x.a<y.a;
		else return x.b<y.b;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		long long ans=0;
		cin>>n;
		for(long long i=1;i<=n;i++){
			cin>>a>>b>>c;
			v[i].a=a;v[i].b=b;v[i].c=c;
			pdd(i,a,b,c);
			f[v[i].fi]++;
			s[v[i].se]++;
			t[v[i].th]++;
		}
		if(f[1]>n/2){
			long long cnt=0;
			sort(v+1,v+n+1,cmp1);
			sort(v+1,v+n+1,cmp);
			for(long long i=1;i<=n;i++){
				if(v[i].xfi==v[i].a){
					ans+=v[i].a,cnt++;
					v[i].flag=1;
				}
				if(cnt==n/2) break;
			}
			for(long long i=1;i<=n;i++){
				if(v[i].flag==0){
					ans+=max(v[i].b,v[i].c);
				}
			}
			cout<<ans<<endl;
		}
		else if(f[2]>n/2){
			long long cnt=0;
			sort(v+1,v+n+1,cmp2);
			sort(v+1,v+n+1,cmp);
			for(long long i=1;i<=n;i++){
				if(v[i].xfi==v[i].b){
					ans+=v[i].b,cnt++;
					v[i].flag=1;
				}
				if(cnt==n/2) break;
			}
			for(long long i=1;i<=n;i++){
				if(v[i].flag==0){
					ans+=max(v[i].a,v[i].c);
				}
			}
			cout<<ans<<endl;
		}
		else if(f[3]>n/2){
			long long cnt=0;
			sort(v+1,v+n+1,cmp3);
			sort(v+1,v+n+1,cmp);
			for(long long i=1;i<=n;i++){
				if(v[i].xfi==v[i].c){
					ans+=v[i].c,cnt++;
					v[i].flag=1;
				}
				if(cnt==n/2) break;
			}
			for(long long i=1;i<=n;i++){
				if(v[i].flag==0){
					ans+=max(v[i].a,v[i].b);
				}
			}
			cout<<ans<<endl;
		}
		else{
			for(long long i=1;i<=n;i++) ans+=v[i].xfi;
			cout<<ans<<endl;
		}
		memset(f,0,sizeof f);
		memset(s,0,sizeof s);
		memset(t,0,sizeof t);
		for(long long i=1;i<=n;i++){
			v[i].a=0,v[i].b=0,v[i].c=0,v[i].fi=0,v[i].se=0,v[i].th=0,v[i].xfi=0,v[i].xse=0,v[i].xth=0,v[i].flag=0;
		}
	}
	return 0;
}
