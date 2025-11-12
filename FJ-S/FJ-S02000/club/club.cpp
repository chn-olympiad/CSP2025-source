#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
int t;
int n;

int a,b,c;
int oa,ob,oc;

int mx=0;
int zz;
struct hh{
	int a,b,c;
}z[100100];

void dfs(int x,int num){
	if(x==n+1){
		mx=max(mx,num);
		return ;
	}
	if(a<zz){
		a++;
		dfs(x+1,num+z[x].a);
		a--;
	}
	if(b<zz){
		b++;
		dfs(x+1,num+z[x].b);
		b--;
	}
	if(c<zz){
		c++;
		dfs(x+1,num+z[x].c);
		c--;
	}
}
bool cmp1(hh x,hh y){
	return x.a>y.a;
}
bool cmp2(hh x,hh y){
	return x.b>y.b;
}
bool cmp3(hh x,hh y){
	return x.c>y.c;
}
void dfsa(int x,int num){
	if(x==n+1){
		mx=max(mx,num);
		return ;
	}
	if(b<zz){
		b++;
		dfs(x+1,num+z[x].b);
		b--;
	}
	if(c<zz){
		c++;
		dfs(x+1,num+z[x].c);
		c--;
	}
}
void dfsb(int x,int num){
	if(x==n+1){
		mx=max(mx,num);
		return ;
	}
	if(a<zz){
		a++;
		dfs(x+1,num+z[x].a);
		a--;
	}
	if(c<zz){
		c++;
		dfs(x+1,num+z[x].c);
		c--;
	}
}
void dfsc(int x,int num){
	if(x==n+1){
		mx=max(mx,num);
		return ;
	}
	if(a<zz){
		a++;
		dfs(x+1,num+z[x].a);
		a--;
	}
	if(b<zz){
		b++;
		dfs(x+1,num+z[x].b);
		b--;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		oa=0,ob=0,oc=0;
		
		for(int i=1;i<=n;i++){
			cin>>z[i].a>>z[i].b>>z[i].c;
			if(z[i].a==0) oa++;
			if(z[i].b==0) ob++;
			if(z[i].c==0) oc++;
		}
		a=0,b=0,c=0;
		mx=0;
		zz=n/2;
		if(oa==n&&ob==n&&oc==n){
			cout<<0<<endl;
			continue;
		}
		else if(ob==n&&oc==n){
			sort(z+1,z+1+n,cmp1);
			for(int i=1;i<=n/2;i++){
				mx+=z[i].a;
			}
		}
		else if(oa==n&&oc==n){
			sort(z+1,z+1+n,cmp2);
			for(int i=1;i<=n/2;i++){
				mx+=z[i].b;
			}
		}
		else if(oa==n&&ob==n){
			sort(z+1,z+1+n,cmp3);
			for(int i=1;i<=n/2;i++){
				mx+=z[i].c;
			}
		}
		else if(oa==n){
			dfsa(1,0);
		}
		else if(ob==n){
			dfsb(1,0);
		}
		else if(oc==n){
			dfsc(1,0);
		}
		else dfs(1,0);
		cout<<mx<<endl;
	}
	return 0;
}
