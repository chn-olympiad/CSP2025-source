#include<bits/stdc++.h>
using namespace std;

struct stu{
	int a;int b;int c;
}st[100001];

int tot,siza,sizb,sizc,n,t,ans,kb,kc;
int vis[100001];

bool cmp(stu x,stu y){
	if(x.a==y.a){
		return x.b<y.b;
	}
	return x.a>y.a;
}

void dfs(int x){
	if(x>n) return;
	if(siza<n/2){
		siza++;tot+=st[x].a;ans = max(ans,tot);
		dfs(x+1);
		siza--;tot-=st[x].a;
	}
	if(sizb<n/2){
		sizb++;tot+=st[x].b;ans = max(ans,tot);
		dfs(x+1);
		sizb--;tot-=st[x].b;
	}
	if(sizc<n/2){
		sizc++;tot+=st[x].c;ans = max(ans,tot);
		dfs(x+1);
		sizc--;tot-=st[x].c;
	}
	return;
}

void dfs2(int x){
	if(x>n) return;
	if(siza<n/2){
		siza++;tot+=st[x].a;ans = max(ans,tot);
		dfs(x+1);
		siza--;tot-=st[x].a;
	}
	if(sizb<n/2){
		sizb++;tot+=st[x].b;ans = max(ans,tot);
		dfs(x+1);
		sizb--;tot-=st[x].b;
	}
	return;
}

void work(){
	memset(vis,0,100001);
	tot=0;siza=0;sizb=0;sizc=0;ans=0;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>st[i].a>>st[i].b>>st[i].c;
	}
	if(n<=30){
		
		dfs(1);
		cout<<ans<<endl;
		return;
	}
	kb =1;kc = 1;
	for(int i = 1;i<=n;i++){
		if(st[i].b!=0)kb=0;
		if(st[i].c!=0)kc=0;
	}
	if(kb&&kc){
		tot = 0;
		sort(st+1,st+n+1,cmp);
		for(int i = 1;i<=n/2;i++){
			tot+=st[i].a;
		}
		cout<<tot<<endl;
		return;
	}
	else if(kc){
		sort(st+1,st+n+1,cmp);
		for(int i = 1;i<=n;i++){
			if(st[i].a>=st[i].b) {
				tot+=st[i].a;siza++;vis[i]=1;
			}
 			if(siza==n/2) break;
		}
		for(int i = 1;i<=n;i++){
			if(!vis[i]) tot+=st[i].b;
		}
		cout<<tot<<endl;
		return;
	}else{
		dfs(1);
		cout<<tot<<endl;
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		work();
	}
	return 0;
}
