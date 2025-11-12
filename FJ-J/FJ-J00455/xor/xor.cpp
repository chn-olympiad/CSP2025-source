#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll read(){
	ll x=0;bool f=0;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f?-x:x;
}

ll n,k,a[500005],sum[500005],ans;
bool fa=1,fb=1;

struct nnn{
	ll l,r;
}p[10000005];

bool cmp(nnn a,nnn b){
	if(a.r==b.r)return a.l<b.l;
	return a.r<b.r;
}

int tot;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read();k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]!=1)fa=0;
		if(a[i]>1)fb=0;
	}
	if(fa==1){
		printf("%lld",n/2);
	}else if(fb==1){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0){ans++;continue ;}
				int cnt=1;
				while(a[i+1]==1){cnt++;i++;}
				ans+=cnt/2;
			}
		}
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1)ans++;
			}			
		}
		printf("%lld",ans);
	}else {
		for(int i=1;i<=n;i++)sum[i]=(sum[i-1] xor a[i]);
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if((sum[i-1] xor sum[j])==k){
					p[++tot].l=i;
					p[tot].r=j;
				}
			}
		}
		sort(p+1,p+tot+1,cmp);
		for(int i=1;i<=tot;i++){
			ans++;
			int sta=i;
			while(p[i+1].l<=p[sta].r)i++;
		}
		printf("%lld",ans);
	}
	return 0;
}
