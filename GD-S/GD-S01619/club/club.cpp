#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct tt{
	int a,b,c,mx;
}a[N];
struct ss{
	int s,id;
}b[N][4];
int k[4],n;
long long ans=0;
long long maxx(long long a,long long b){
	if(a>b) return a;
	else return b;
}
void dfs(int k,int x,int y,int z,long long s){
	bool f=0;
	if(k>=n+1){
		ans=maxx(ans,s);
		f=1;
	}
	if(!f){
		if(x<n/2) dfs(k+1,x+1,y,z,s+a[k].a);
		if(y<n/2) dfs(k+1,x,y+1,z,s+a[k].b);
		if(z<n/2) dfs(k+1,x,y,z+1,s+a[k].c);
	}
}
bool cmp(tt x,tt y){
	return x.mx>y.mx;
}
bool cmp1(ss x,ss y){
	return x.s>y.s;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(k,0,sizeof(k));
		cin>>n;
		ans=0;
		bool f=1,g=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			b[i][1].s=a[i].a;b[i][2].s=a[i].b;b[i][3].s=a[i].c;
			b[i][1].id=1;b[i][2].id=2;b[i][3].id=3;
			a[i].mx=max(a[i].a,(a[i].b,a[i].c));
			if(a[i].c!=0) f=0;g=0;
			if(a[i].b!=0) g=0;
		}
		if(g){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++) ans+=a[i].a;
		}
		else if(n<=20) dfs(1,0,0,0,0);
		else{
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n;i++){
				sort(b[i]+1,b[i]+4,cmp1);
				if(k[b[i][1].id]<n/2){
					ans+=b[i][1].s;
					k[b[i][1].id]++;
				}
				else{
					if(k[b[i][2].id]<n/2){
						ans+=b[i][2].s;
						k[b[i][2].id]++;
					}
					else{
						ans+=b[i][3].s;
						k[b[i][3].id]++;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
	//rp++
} 
