#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pb emplace_back
#define fr first
#define sc second
typedef const int Int;
typedef pair<int,int> pii;

inline  Int read(){
	int x=0;char c=getchar();bool f=(c=='-');
	while(!isdigit(c))c=getchar(),f|=(c=='-');
	while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return f?-x:x;
}

Int N=1e5+5;

int n;

struct meb{
	int a,b,c;
}A[N];

vector <meb> a,b,c;

void solve(){
	int ans=0;
	n=read();
	for(int i=1;i<=n;i++)A[i].a=read(),A[i].b=read(),A[i].c=read();
	for(int i=1;i<=n;i++){
		if(A[i].a>=max(A[i].b,A[i].c))a.pb(A[i]),ans+=A[i].a;
		else if(A[i].b>=max(A[i].a,A[i].c))b.pb(A[i]),ans+=A[i].b;
		else c.pb(A[i]),ans+=A[i].c;
	}
	if(a.size()>n/2){
		sort(a.begin(),a.end(),[](const meb &a,const meb &b){
			return a.a-max(a.b,a.c)<b.a-max(b.b,b.c);
		});
		for(int i=0;i<a.size()-n/2;i++)ans+=max(a[i].b,a[i].c)-a[i].a;
	}
	if(b.size()>n/2){
//		cout<<"x ok"<<endl;
		sort(b.begin(),b.end(),[](const meb &a,const meb &b){
			return a.b-max(a.a,a.c)<b.b-max(b.a,b.c);
		});
		for(int i=0;i<b.size()-n/2;i++)ans+=max(b[i].a,b[i].c)-b[i].b;
//		cout<<"ok"<<endl;
	}
	if(c.size()>n/2){
		sort(c.begin(),c.end(),[](const meb &a,const meb &b){
			return a.c-max(a.b,a.a)<b.c-max(b.a,b.b);
		});
		for(int i=0;i<c.size()-n/2;i++)ans+=max(c[i].b,c[i].a)-c[i].c;
	}
	printf("%d\n",ans);
	a.clear(),b.clear(),c.clear();
}

int T;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--)solve();
	return 0;
}

































