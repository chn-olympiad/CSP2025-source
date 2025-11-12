#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
struct st{
	int a,b,c,d12,d13,d23;
}p[100005];
int t,n,ans=0,sa=0,sb=0,sc=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		sa=0,sb=0,sc=0;
		ans=0;
		memset(p,0,sizeof(p));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			p[i].a=read(),p[i].b=read(),p[i].c=read();
			p[i].d12=abs(p[i].a-p[i].b);
			p[i].d13=abs(p[i].a-p[i].c);
			p[i].d23=abs(p[i].b-p[i].c);
		}
		for(int i=1;i<=n;i++){
			int x;
			x=max(p[i].a,max(p[i].b,p[i].c));
			if(x==p[i].a) sa++;
			else if(x==p[i].b) sb++;
			else sc++;
			ans+=x;
		}
		if(sa>n/2){
			while(sa>n/2){
				int mn=1e9,x;
				for(int i=1;i<=n;i++){
					x=max(p[i].a,max(p[i].b,p[i].c));
					if(x==p[i].a){
						mn=min(mn,min(p[i].d12,p[i].d13));
					}
				}
				ans-=mn;
				sa--;
			}
		}
		if(sb>n/2){
			while(sb>n/2){
				int mn=1e9,x;
				for(int i=1;i<=n;i++){
					x=max(p[i].a,max(p[i].b,p[i].c));
					if(x==p[i].b){
						mn=min(mn,min(p[i].d12,p[i].d23));
					}
				}
				ans-=mn;
				sb--;
			}
		}
		if(sc>n/2){
			while(sc>n/2){
				int mn=1e9,x;
				for(int i=1;i<=n;i++){
					x=max(p[i].a,max(p[i].b,p[i].c));
					if(x==p[i].c){
						mn=min(mn,min(p[i].d23,p[i].d13));
					}
				}
				ans-=mn;
				sc--;
			}
		}
		printf("%d\n",ans);
	}
}
