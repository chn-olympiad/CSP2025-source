#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N=100005;

int rd1(){
	int a=0,f=1;
	char c;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-f;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=a*10+c-'0';
		c=getchar();
	} 
	return a*f;
}

ll rd2(){
	ll a=0,f=1;
	char c;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-f;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=a*10+c-'0';
		c=getchar();
	} 
	return a*f;
}

struct Cl{
	ll a;
	ll b;
	ll c;
};

int t;
int n,m;
Cl v[N];
ll ans;

void dfs(int x,int a,int b,int c,ll sum){
	if(a>m||b>m||c>m){
		return;
	}
	if(x>n){
		ans=max(ans,sum);
		return;
	}
	dfs(x+1,a+1,b,c,sum+v[x].a);
	dfs(x+1,a,b+1,c,sum+v[x].b);
	dfs(x+1,a,b,c+1,sum+v[x].c);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=rd1();
	while(t--){
		n=rd1();
		for(int i=1;i<=n;i++){
			v[i].a=rd2(),v[i].b=rd2(),v[i].c=rd2();
		}
		m=n/2;
		ans=0;
		dfs(1,0,0,0,0);
		printf("%lld\n",ans);
	} 
	return 0;
}