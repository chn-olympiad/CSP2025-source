#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n;
long long sm=0,mx=0;
struct N{
	int a,b,c;
}a[MAXN];
struct M{
	int m=0,a=0,b=0,c=0;
}d[MAXN][5];
void dfs(int p,int a1,int b1,int c1){
	if(p>n) {mx=max(sm,mx);
	//cout<<sm<<endl;
	//cout<<a1<<' '<<b1<<' '<<c1<<endl;
	return;}
	if(a1<n/2){
		sm+=a[p].a;
		dfs(p+1,a1+1,b1,c1);
		sm-=a[p].a;
	}
	if(b1<n/2){
		sm+=a[p].b;
		dfs(p+1,a1,b1+1,c1);
		sm-=a[p].b;
	}
	if(c1<n/2){
		sm+=a[p].c;
		dfs(p+1,a1,b1,c1+1);
		sm-=a[p].c;
	}
}
bool cmp(N a,N b){
	return a.a>b.a;
}
bool cmp2(N a,N b){
	return a.b>b.b;
}
bool cmp3(N a,N b){
	return a.c>b.c;
}
void solve(){
	sm=0,mx=0;
	cin>>n;
	for(int i=1;i<=n;i++){
			scanf("%d",&a[i].a);
			scanf("%d",&a[i].b);
			scanf("%d",&a[i].c);
	}
	if(n<=15){
		dfs(1,0,0,0);
		cout<<mx<<endl;
	}
	else if(a[n].b==0 and a[n].c==0){
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			sm+=a[i].a;
		}
		cout<<sm<<endl;
	}
	else if(a[n].a==0 and a[n].c==0){
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n/2;i++){
			sm+=a[i].b;
		}
		cout<<sm<<endl;
	}
	else if(a[n].a==0 and a[n].b==0){
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n/2;i++){
			sm+=a[i].c;
		}
		cout<<sm<<endl;
	}
	else{
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		
		int mx=-1,mi=0;
		for(int j=1;j<=3;j++){
			if(d[i-1][j].a<n/2){
				if(d[i-1][j].m+a[i].a>mx){
					mx=d[i-1][j].m+a[i].a;
					mi=j;
				}
			}
		}
		d[i][1].m=mx;
		d[i][1].a=d[i-1][mi].a+1;
		d[i][1].b=d[i-1][mi].b;
		d[i][1].c=d[i-1][mi].c;
		
		mx=-1,mi=0;
		for(int j=1;j<=3;j++){
			if(d[i-1][j].b<n/2){
				if(d[i-1][j].m+a[i].b>mx){
					mx=d[i-1][j].m+a[i].b;
					mi=j;
				}
			}
		}
		d[i][2].m=mx;
		d[i][2].a=d[i-1][mi].a;
		d[i][2].b=d[i-1][mi].b+1;
		d[i][2].c=d[i-1][mi].c;
		
		mx=-1,mi=0;
		for(int j=1;j<=3;j++){
			if(d[i-1][j].c<n/2){
				if(d[i-1][j].m+a[i].c>mx){
					mx=d[i-1][j].m+a[i].c;
					mi=j;
				}
			}
		}
		d[i][3].m=mx;
		d[i][3].a=d[i-1][mi].a;
		d[i][3].b=d[i-1][mi].b;
		d[i][3].c=d[i-1][mi].c+1;
		
	}
	cout<<max(d[n][1].m,max(d[n][2].m,d[n][3].m))<<endl;
		
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
