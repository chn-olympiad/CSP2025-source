#include<bits/stdc++.h>
#define int long long 
#define MAXN 100005 
int gi(){
	char c;int x=0,f=0;
	while(!isdigit(c=getchar()))f|=(c=='-');
	while(isdigit(c))x=(x*10)+(c^48),c=getchar();
	return f?-x:x;
}
std::mt19937 rnd(std::random_device{}());
#define pr std::pair<int,int>
#define all(x) (x).begin(),(x).end() 
#define mem(x,w) memest(x,w,sizeof(x)) 
#define sz(x) (int)((x).size()) 
#define fi first
#define se second 
template<class T>void cxk(T&a,T b){a=a>b?a:b;}
template<class T>void cnk(T&a,T b){a=a<b?a:b;}
int n,a[MAXN][4];
pr b[4];
std::priority_queue<int>q[4];
void work(){
	n=gi();int ans=0;
	for(int i=1;i<=3;i++)while(!q[i].empty())q[i].pop();
	for(int i=1;i<=n;i++){
		a[i][1]=gi(),a[i][2]=gi(),a[i][3]=gi();
		b[1]=pr(a[i][1],1),b[2]=pr(a[i][2],2),b[3]=pr(a[i][3],3);
		std::sort(b+1,b+4,[&](pr i,pr j){return i.fi>j.fi;});
		q[b[1].se].push(-b[1].fi+b[2].fi),ans+=b[1].fi;
	}
	if(sz(q[1])<=n/2&&sz(q[2])<=n/2&&sz(q[3])<=n/2)return printf("%lld\n",ans),void();
	int p;
	if(sz(q[1])>n/2)p=1;
	else if(sz(q[2])>n/2)p=2;
	else p=3;
	while(sz(q[p])>n/2){int u=q[p].top();ans+=u;q[p].pop();}
	printf("%lld\n",ans);
}
signed main(){
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	int t=gi();while(t--)work();
	return 0;
}

