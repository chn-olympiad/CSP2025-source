#include<bits/stdc++.h>
using namespace std;
int t,ans,n;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
struct node{
	int a,b,c;
}a[100010];
bool cmpa(node x,node y){
	return x.a>y.a;
}
bool cmpb(node x,node y){
	return x.c>y.c;
}
void dfs(int k,int ya,int yb,int yc,int su){
	if(k>n){
		ans=max(ans,su);
		return;
	}
	if(ya>0)dfs(k+1,ya-1,yb,yc,su+a[k].a);
	if(yb>0)dfs(k+1,ya,yb-1,yc,su+a[k].b);
	if(yc>0)dfs(k+1,ya,yb,yc-1,su+a[k].c);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	for(int i=1;i<=t;i++){
		int ta=1,tb=1,sum=0;
		ans=0;
		n=read();
		for(int i=1;i<=n;i++){
			a[i].a=read();
			a[i].b=read();
			a[i].c=read();
			if(a[i].c!=0){
				ta=0;
				tb=0;
			}else if(a[i].b!=0){
				ta=0;
			}
		}
		if(ta){
			sort(a+1,a+n+1,cmpa);
			for(int i=1;i<=n/2;i++){
				sum+=a[i].a;
			}
			cout<<sum;
		}else if(tb){
			for(int i=1;i<=n;i++){
				a[i].c=abs(a[i].b-a[i].a);
			}
			sort(a+1,a+n+1,cmpb);
			int e=-1,ya=n/2,yb=n/2;
			for(int i=1;i<=n;i++){
				bool e2=(a[i].a>a[i].b);
				if(e2){
					if(ya==0){
						sum+=a[i].b;
					}else{
						sum+=a[i].a;
						ya--;
					}
				}else{
					if(yb==0){
						sum+=a[i].a;
					}else{
						sum+=a[i].b;
						yb--;
					}
				}
			}
			cout<<sum;
		}else{
			dfs(1,n/2,n/2,n/2,0);
			cout<<ans;
		}
	}
	return 0;
}
