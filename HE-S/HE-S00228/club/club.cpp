#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>inline void read(T&x){
	x=0;char c;int sgin=1;
	do{
		c=getchar();
		if(c=='-')sgin=-1;
	}while(!isdigit(c));
	do{
		x=(x<<3)+(x<<1)+(c&15);
		c=getchar();
	}while(isdigit(c));
	x*=sgin;
}

struct node{
	int a,b,c;
}a[100010];

int b[100010];

bool cmp(int a,int b){
	return a>b;
}

void solve(){
	int n,ans=0;
	read(n);
	int cnta=0,cntb=0,cntc=0,cntab=0,cntac=0,cntbc=0,cntabc=0;
	for(int i=1;i<=n;i++){
		read(a[i].a);
		read(a[i].b);
		read(a[i].c);
 		if(a[i].a>a[i].b){
			if(a[i].a>a[i].c)cnta++,ans+=a[i].a;
			else if(a[i].a==a[i].c)cntac++,ans+=a[i].a;
			else cntc++,ans+=a[i].c;
		}
		else if(a[i].a==a[i].b){
			if(a[i].a>a[i].c)cntab++,ans+=a[i].a;
			else if(a[i].a==a[i].c)cntabc++,ans+=a[i].a;
			else cntc++,ans+=a[i].c;
		}
		else{
			if(a[i].a>a[i].c)cntb++,ans+=a[i].b;
			else if(a[i].a==a[i].c)cntb++,ans+=a[i].b;
			else if(a[i].b>a[i].c)cntb++,ans+=a[i].b;
			else if(a[i].b==a[i].c)cntbc++,ans+=a[i].b;
			else cntc++,ans+=a[i].c;
		}
	}
	if(cntab!=0){
		if(cnta<n/2){
			if(n/2-cnta>=cntab)cnta+=cntab,cntab=0;
			else cntab-=(n/2-cnta),cnta=n/2;
		}
		if(cntb<n/2){
			if(n/2-cntb>=cntab)cntb+=cntab,cntab=0;
			else cntab-=(n/2-cntb),cntb=n/2;
		}
	}
	if(cntac!=0){
		if(cnta<n/2){
			if(n/2-cnta>=cntac)cnta+=cntac,cntac=0;
			else cntac-=(n/2-cnta),cnta=n/2;
		}
		if(cntc<n/2){
			if(n/2-cntc>=cntac)cntc+=cntac,cntac=0;
			else cntac-=(n/2-cntc),cntc=n/2;
		}
	}
	if(cntbc!=0){
		if(cntc<n/2){
			if(n/2-cntc>=cntbc)cntc+=cntbc,cntbc=0;
			else cntbc-=(n/2-cntc),cntc=n/2;
		}
		if(cntb<n/2){
			if(n/2-cntb>=cntbc)cntb+=cntbc,cntbc=0;
			else cntbc-=(n/2-cntb),cntb=n/2;
		}
	}
	int top=0;
	if(cnta>n/2){
		for(int i=1;i<=n;i++){
			if(a[i].a>a[i].b&&a[i].a>a[i].c){
				b[++top]=max(a[i].b,a[i].c)-a[i].a;
			}
		}
		sort(b+1,b+1+top,cmp);
		for(int i=1;cnta>n/2;i++){
			cnta--;
			ans+=b[i];
		}
	}
	if(cntb>n/2){
		for(int i=1;i<=n;i++){
			if(a[i].b>a[i].a&&a[i].b>a[i].c){
				b[++top]=max(a[i].a,a[i].c)-a[i].b;
			}
		}
		sort(b+1,b+1+top,cmp);
		for(int i=1;cntb>n/2;i++){
			cntb--;
			ans+=b[i];
		}
	}
	if(cntc>n/2){
		for(int i=1;i<=n;i++){
			if(a[i].c>a[i].b&&a[i].c>a[i].a){
				b[++top]=max(a[i].b,a[i].a)-a[i].c;
			}
		}
		sort(b+1,b+1+top,cmp);
		for(int i=1;cntc>n/2;i++){
			cntc--;
			ans+=b[i];
		}
	}
	printf("%d\n",ans);
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	read(t);
	while(t--)solve();
	return 0;
}
