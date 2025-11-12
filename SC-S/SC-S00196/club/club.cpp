#include <bits/stdc++.h>
using namespace std;
const int MAX_N=100010;
int T;
int n,c1=0,c2=0,c3=0;
long long ans=0;
struct node{
	int a,b,c;
}a[MAX_N];
bool cmp(node x,node y){
	int x1=max(x.a,max(x.b,x.c));
	int x2=x.a+x.b+x.c-x1-min(x.a,min(x.b,x.c));
	int y1=max(y.a,max(y.b,y.c));
	int y2=y.a+y.b+y.c-y1-min(y.a,min(y.b,y.c));
	if(x1-x2==y1-y2) return x1>y1;
	else return (x1-x2)>(y1-y2);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	bool FA=1;
	cin>>T;
	while(T--){
		ans=c1=c2=c3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].b!=0||a[i].c!=0) FA=0;
		}
		sort(a+1,a+1+n,cmp);
		if(FA){
			for(int i=1;i<=n/2;i++){
				ans+=a[i].a;
			}
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			if(a[i].a>a[i].b&&a[i].a>a[i].c){
				if(c1<n/2){
					c1++;
					ans+=a[i].a;
				}else{
					if(a[i].b>a[i].c){
						c2++;
						ans+=a[i].b;
					}else if(a[i].c>a[i].b){
						c3++;
						ans+=a[i].c;
					}else{
						ans+=a[i].b;
					}
				}
			}else if(a[i].b>a[i].a&&a[i].b>a[i].c){
				if(c2<n/2){
					c2++;
					ans+=a[i].b;
				}else{
					if(a[i].a>a[i].c){
						c1++;
						ans+=a[i].a;
					}else if(a[i].c>a[i].a){
						c3++;
						ans+=a[i].c;
					}else{
						ans+=a[i].a;
					}
				}
			}else if(a[i].c>a[i].a&&a[i].c>a[i].b){
				if(c3<n/2){
					c3++;
					ans+=a[i].c;
				}else{
					if(a[i].a>a[i].b){
						c1++;
						ans+=a[i].a;
					}else if(a[i].b>a[i].a){
						c2++;
						ans+=a[i].b;
					}else{
						ans+=a[i].a;
					}
				}
			}else{
				ans+=a[i].a;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
