#include<bits/stdc++.h>
#define FILE(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
#define ll long long
using namespace std;
const int N=1e5+10;
struct Usee{
	int a,i;
};
struct Node{
	Usee a,b,c;
};
Node a[N];
int n,T;
ll ans;
int t[4];
bool cmp(Node x,Node y){
	return x.a.a>y.a.a;
}
void ss(Node &x){
	if(x.a.a<x.b.a){
		swap(x.a,x.b);
	}
	if(x.b.a<x.c.a){
		swap(x.b,x.c);
	}
	if(x.a.a<x.b.a){
		swap(x.a,x.b);
	}
}
void init(){
	memset(t,0,sizeof(t));
	memset(a,0,sizeof(a));
	ans=0;
}
int main(){
	FILE("club");
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		init();
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a.a>>a[i].b.a>>a[i].c.a;
			a[i].a.i=1;
			a[i].b.i=2;
			a[i].c.i=3;
			ss(a[i]);
		}
		sort(a+1,a+1+n,cmp);
		priority_queue<int,vector<int>,less<int> > q[4][4];
		for(int i=1;i<=n;i++){
			if(t[a[i].a.i]<n/2){
				t[a[i].a.i]++;
				q[a[i].a.i][a[i].b.i].push(a[i].b.a-a[i].a.a);
				q[a[i].a.i][a[i].c.i].push(a[i].c.a-a[i].a.a);
				ans+=a[i].a.a;
			}
			else{
				int b=q[a[i].a.i][a[i].b.i].top()+a[i].a.a;
				int c=q[a[i].a.i][a[i].c.i].top()+a[i].a.a;
				if(b>c){
					t[a[i].b.i]++;
					if(b<a[i].b.a){
						ans+=a[i].b.a;
					}
					else{
						ans+=b;
						q[a[i].a.i][a[i].b.i].pop();
						q[a[i].a.i][a[i].b.i].push(a[i].b.a-a[i].a.a);
						q[a[i].a.i][a[i].c.i].push(a[i].c.a-a[i].a.a);
					}
				}
				else{
					if(c<a[i].b.a){
						t[a[i].b.i]++;
						ans+=a[i].b.a;
					}
					else{
						t[a[i].c.i]++;
						ans+=c;
						q[a[i].a.i][a[i].c.i].pop();
						q[a[i].a.i][a[i].b.i].push(a[i].b.a-a[i].a.a);
						q[a[i].a.i][a[i].c.i].push(a[i].c.a-a[i].a.a);
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
