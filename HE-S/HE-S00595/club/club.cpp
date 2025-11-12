#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
//struct Person{
//	int a;
//	int b;
//	int c;
//	int wm;
//	int cm;
//} p[MAXN];
//bool cmp(Person x,Person y){
//	int x_m,x_cm,y_m,y_cm;
//	if(x.a>=x.b&&x.a>=x.c){
//		x.wm=1,x_m=x.a;
//		x.cm=(x.b>x.c?2:3);
//		x_cm=max(x.b,x.c);
//	} 
//	else if(x.b>=x.a&&x.b>=x.c){
//		x.wm=2,x_m=x.b;
//		x.cm=(x.a>x.c?1:3);
//		x_cm=max(x.a,x.c);
//	} 
//	else if(x.c>=x.a&&x.c>=x.b){
//		x.wm=3,x_m=x.c;
//		x.cm=(x.a>x.b?1:2);
//		x_cm=max(x.a,x.b);
//	} 
//	if(y.a>=y.b&&y.a>=y.c){
//		y.wm=1,y_m=y.a;
//		y.cm=(y.b>y.c?2:3);
//		y_cm=max(y.b,y.c);
//	} 
//	else if(y.b>=y.a&&y.b>=y.c){
//		y.wm=2,y_m=y.b;
//		y.cm=(y.a>y.c?1:3);
//		y_cm=max(y.a,y.c);
//	} 
//	else if(y.c>=y.a&&y.c>=y.b){
//		y.wm=3,y_m=y.c;
//		y.cm=(y.a>y.b?1:2);
//		y_cm=max(y.a,y.b);
//	} 
//	if(x_cm!=y_cm) return x_cm>y_cm;
//	return x_m>y_m;
//}
//map<int,int> a,b,c;
//void init(){
//	for(auto it:p){
//		if(it.wm==1){
//			if(it.cm==2) a.push_back(it.a,it.b);
//			if(it.cm==3) a.push_back(it.a,it.c);
//		}
//		if(it.wm==2){
//			if(it.cm==1) b.push_back(it.b,it.a);
//			if(it.cm==3) b.push_back(it.b,it.c);
//		}
//		if(it.wm==3){
//			if(it.cm==1) c.push_back(it.c,it.a);
//			if(it.cm==2) c.push_back(it.c,it.b);
//		}
//	}
//}
//int T;
//int main(){
//	//freopen("club.in","r",stdin);
//	//freopen("club.out","w",stdout);
//	cin>>T;
//	while(T--){
//		memset(p,0,sizeof(p));
//		memset(dp,0,sizeof(dp));
//		int n,ans=0; cin>>n;
//		for(int i=1;i<=n;i++)
//			cin>>p[i].a>>p[i].b>>p[i].c;
//		sort(p+1,p+1+n,cmp);
//		init();
//		int c1=a.size(),c2=b.size(),c3=c.size();
//		if(c1>n/2){
//			bool f=true;
//			for(auto it:a){
//				if(f){ans=it.a;f=false;continue;}
//				if((it-1).b>=it)
//			}
//		}
//	}
//	return 0;
//} 
int a[MAXN];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		if(n==2){
			int a,b,c,d,e,f;
			cin>>a>>b>>c>>d>>e>>>f;
			if(a>b&&a>c&&d>e&&d>f) cout<<max(a+max(e,f),d+max(b,c));
			else if(b>a&&b>c&&e>d&&e>f) cout<<max(b+max(d,f),e+max(a,c));
			else if(c>a&&c>b&&f>d&&f>e) cout<<max(c+max(d,e),f+max(a,b));
			else cout<<max(a,max(b,c))+max(d,max(e,f));
		} else {
			for(int i=1;i<=n;i++){
				int p,q;
				cin>>a[i]>>p>>q;
			} sort(a+1,a+1+n);
			int ans=0;
			for(int i=n;i>=n/2;i--)
				ans+=a[i];
			cout<<ans;
		}
	}
	return 0;
}
