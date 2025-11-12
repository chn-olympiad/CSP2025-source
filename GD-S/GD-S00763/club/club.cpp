#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+1e4;
const ll linf=1e16;
int n;
struct node{
	ll a,b,c;
	ll cm;
	ll cp;
	bool u=0;
};
node a[N];


bool operator<(node a,node b){
	return a.cm>b.cm;
}

int p[10];
int T;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].a>a[i].b && a[i].a>a[i].c){
				a[i].cp=1;
				a[i].cm=a[i].a-max(a[i].b,a[i].c);
			}
			else if(a[i].b>a[i].c){
				a[i].cp=2;
				a[i].cm=a[i].b-max(a[i].a,a[i].c);
			}
			else{
				a[i].cp=3;
				a[i].cm=a[i].c-max(a[i].a,a[i].b);
			}
			a[i].u=0;
		}
		ll ans=0;
		sort(a+1,a+1+n);
		memset(p,0,sizeof(p));
		for(int i=1;i<=n;i++){
			if(a[i].u) continue;
			if(p[a[i].cp]<n/2){
				if(a[i].cp==1) ans+=a[i].a;
				else if(a[i].cp==2) ans+=a[i].b;
				else ans+=a[i].c;
				a[i].u=1;
				p[a[i].cp]++;
			}
			else{
				if(a[i].cp==1) a[i].a=-linf;
				else if(a[i].cp==2) a[i].b=-linf;
				else a[i].c=-linf;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i].a>a[i].b && a[i].a>a[i].c){
				a[i].cp=1;
				a[i].cm=a[i].a-max(a[i].b,a[i].c);
			}
			else if(a[i].b>a[i].c){
				a[i].cp=2;
				a[i].cm=a[i].b-max(a[i].a,a[i].c);
			}
			else{
				a[i].cp=3;
				a[i].cm=a[i].c-max(a[i].a,a[i].b);
			}
		}
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			if(a[i].u) continue;
			if(a[i].cp==1) ans+=a[i].a;
			else if(a[i].cp==2) ans+=a[i].b;
			else ans+=a[i].c;
			a[i].u=1;
			p[a[i].cp]++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
