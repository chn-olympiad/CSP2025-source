#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct person{
    int a,b,c;
}s[N],a[N],b[N],c[N];
int n,T;
long long ans=0;
int l1,l2,l3;
inline int promax(int x,int y,int z){
	if(x>y&&x>z) return max(y,z);
	if(y>x&&y>z) return max(x,z);
	return max(x,y);
}
inline bool cmp(person x,person y){
	int t1,t2;
	t1=max(x.a,max(x.b,x.c))-promax(x.a,x.b,x.c);
	t2=max(y.a,max(y.b,y.c))-promax(y.a,y.b,y.c);
	return t1>t2;
	
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
	while(T--){
		ans=l1=l2=l3=0;
		cin>>n;
		for(int i=1;i<=n;i++) scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
		sort(s+1,s+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(s[i].a>=s[i].b&&s[i].a>=s[i].c) a[++l1]=s[i];
			else if(s[i].b>=s[i].c) b[++l2]=s[i];
			else c[++l3]=s[i];
		}
		if(l1>n/2){
			for(;l1>n/2;l1--){
				if(promax(a[l1].a,a[l1].b,a[l1].c)==a[l1].b) b[++l2]=a[l1];
				else c[++l3]=a[l1];
			}
		}else if(l2>n/2){
			for(;l2>n/2;l2--){
				if(promax(b[l2].a,b[l2].b,b[l2].c)==b[l2].a) a[++l1]=b[l2];
				else c[++l3]=b[l2];
			}
		}else if(l3>n/2){
			for(;l3>n/2;l3--){
				if(promax(c[l3].a,c[l3].b,c[l3].c)==c[l3].a) a[++l1]=c[l3];
				else b[++l2]=c[l3];
			}
		}
		for(int i=1;i<=l1;i++) ans+=a[i].a;
		for(int i=1;i<=l2;i++) ans+=b[i].b;
		for(int i=1;i<=l3;i++) ans+=c[i].c;
		cout<<ans<<endl;
	}
}
