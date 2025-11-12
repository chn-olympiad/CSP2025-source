#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=2e5+5;
int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+ch-48,ch=getchar();
	return x*f;
}
int n;
int ma[N],mi[N],h[N];
int cnt,p,s1,s2,s3;
ll ans;
void solve(){
	n=read();ans=s1=s2=s3=0;
	for(int i=1,a,b,c;i<=n;i++){
		a=read();b=read();c=read();
		if(a>=b&&a>=c){
			ma[i]=1;
			ans+=a;
			s1++;
			mi[i]=min(a-b,a-c);
		}else 
		if(b>=a&&b>=c){
			ma[i]=2;
			ans+=b;
			s2++;
			mi[i]=min(b-a,b-c);
		}else 
		if(c>=b&&c>=a){
			ma[i]=3;
			ans+=c;
			s3++;
			mi[i]=min(c-b,c-a);
		}
	}
	cnt=0;p=0;
	if(s1*2>n){
		p=s1-n/2;
		for(int i=1;i<=n;i++)
			if(ma[i]==1)h[++cnt]=mi[i];
	}
	if(s2*2>n){
		p=s2-n/2;
		for(int i=1;i<=n;i++)
			if(ma[i]==2)h[++cnt]=mi[i];
	}
	if(s3*2>n){
		p=s3-n/2;
		for(int i=1;i<=n;i++)
			if(ma[i]==3)h[++cnt]=mi[i];
	}
	sort(h+1,h+1+cnt);
	for(int i=1;i<=p;i++)ans-=h[i];
	printf("%lld\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--)solve(); 
	return 0;
}
