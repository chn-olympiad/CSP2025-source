#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
struct node{
	int id,val;
};

bool cmp(node a,node b){
	if(a.val==b.val){
		return a.id<b.id;
	}
	return a.val>b.val;
}
node a[N],b[N],c[N];
int vis[N];
void init(){
	memset(vis,0,sizeof vis);
}

int n;
int maxx;
void dfs(int x,int cnt,int a1,int b1,int c1){
	if(x>n){
		if(a1>n/2)return;
		if(b1>n/2)return;
		if(c1>n/2)return;
		
		maxx=max(maxx,cnt);
		
		return;
	}
	dfs(x+1,cnt+a[x].val ,a1+1,b1,c1);
	dfs(x+1,cnt+b[x].val ,a1,b1+1,c1);
	dfs(x+1,cnt+c[x].val ,a1,b1,c1+1);
}
void solm(){
	dfs(1,0,0,0,0);
	cout<<maxx<<'\n';
	maxx=0;
	
}

void solA(){
	sort(a+1,a+n+1,cmp);
	int ans=0;
	for(int i = 1;i<=n/2;i++){
		ans+=a[i].val;
	}
	cout<<ans;	
}


void solB(){
	//对半分 
	
	
}

void solD(){
	//在第i个选择...的maxx 
	
}
void sol(){
	cin>>n;
	bool wkA=1;
	bool wkB=1;
	bool wkC=1;
	
	for(int i = 1;i<=n;i++){
		cin>>a[i].val;
		cin>>b[i].val;
		cin>>c[i].val;
		
		a[i].id=b[i].id=c[i].id=i;
		if(b[i].val!=0||c[i].val!=0)wkA=0;
		if(c[i].val!=0)wkB=0;
	}
	if(n<=10){
		solm();
		return;
	}
	
	if(wkA){
		solA();
	}else if(wkB){
		solB();
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T;
	cin>>T;
	
	while(T--){
		sol();
	}
	
	
	
	return 0;
} 
