#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+1;
long long js(long long a,long long b,long long c){
	if(a>=b&&a>=c)return 1;
	if(b>=c&&b>=a)return 2;
	return 3;
}
struct edge{
	long long a,b,c;
}a[N];
long long n,gg[N];
void work(){
	cin>>n;
	memset(gg,0,sizeof(gg));
	for(long long i=1;i<=n;++i){
		cin>>a[i].a>>a[i].b>>a[i].c;
	}
	long long a1=0,b1=0,c1=0,ans=0;
	for(long long i=1;i<=n;++i){
		long long tmp=js(a[i].a,a[i].b,a[i].c);
		if(tmp==1){
			a1++;ans+=a[i].a;
		}else if(tmp==2){
			b1++;ans+=a[i].b;
		}else if(tmp==3){
			c1++;ans+=a[i].c;
		}
	}
	if(a1<=n/2&&b1<=n/2&&c1<=n/2){
		cout<<ans<<endl;
		return;
	}
	long long cnt=0;
	for(long long i=1;i<=n;++i){
		long long tmp=js(a[i].a,a[i].b,a[i].c);
		if(tmp==1&&a1>n/2)gg[++cnt]=a[i].a-max(a[i].b,a[i].c);
		if(tmp==2&&b1>n/2)gg[++cnt]=a[i].b-max(a[i].a,a[i].c);
		if(tmp==3&&c1>n/2)gg[++cnt]=a[i].c-max(a[i].b,a[i].a);
	}
	sort(gg+1,gg+1+cnt);
	for(long long i=1;i<=max(a1,max(b1,c1))-n/2;++i){
		ans-=gg[i];
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.ans","w",stdout); 
	long long T;cin>>T;
	while(T--)work();
	return 0;
}
