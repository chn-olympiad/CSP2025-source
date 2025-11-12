#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[100005][5];
struct we{
	int num;
	int o;
};
struct st{
	int num;
	we a[4];
}t[100005];
int c[5];
st pai[100005];
ll n,ans;
bool cmp(st q,st p){
	if(q.a[1].num!=p.a[1].num) return q.a[1].num>p.a[1].num;
	if(q.a[2].num!=p.a[2].num) return q.a[2].num>p.a[2].num;
	return q.a[3].num>p.a[3].num;
}
bool opt(we q,we p){
	return q.num>p.num;
}
bool cmda(st q,st p){
	if(q.a[2].num!=p.a[2].num) return q.a[2].num>p.a[2].num;
	return q.a[3].num>p.a[3].num;
}
bool pmda(st q,st p){
	if(q.a[3].num!=p.a[3].num) return q.a[3].num>p.a[3].num;
	return q.a[2].num>p.a[2].num;
}
bool cmdb(st q,st p){
	if(q.a[1].num!=p.a[1].num) return q.a[1].num>p.a[1].num;
	return q.a[3].num>p.a[3].num;
}
bool pmdb(st q,st p){
	if(q.a[3].num!=p.a[3].num) return q.a[3].num>p.a[3].num;
	return q.a[1].num>p.a[1].num;
}
bool cmdc(st q,st p){
	if(q.a[2].num!=p.a[2].num) return q.a[2].num>p.a[2].num;
	return q.a[1].num>p.a[1].num;
}
bool pmdc(st q,st p){
	if(q.a[1].num!=p.a[1].num) return q.a[1].num>p.a[1].num;
	return q.a[2].num>p.a[2].num;
}
ll fa(int v){
	int s=0;
	memset(pai,0,sizeof(pai));
	for(int i=v,j=1;i<=n;i++){
		pai[j]=t[i];
		s++;
	}
	sort(pai+1,pai+s+1,cmda);
	for(int i=1;i<=s;i++){
		for(int j=1;j<=3;j++){
			if(pai[i].a[j].o==1) continue;
			c[pai[i].a[j].o]++;
			ans+=pai[i].a[j].num;
			break; 
		}
	}
}
ll fb(int v){
	int s=0;
	memset(pai,0,sizeof(pai));
	for(int i=v,j=1;i<=n;i++){
		pai[j]=t[i];
		s++;
	}
	sort(pai+1,pai+s+1,cmdb);
	for(int i=1;i<=s;i++){
		for(int j=1;j<=3;j++){
			if(pai[i].a[j].o==2) continue;
			c[pai[i].a[j].o]++;
			ans+=pai[i].a[j].num;
			break; 
		}
	}
}
ll fc(int v){
	int s=0;
	memset(pai,0,sizeof(pai));
	for(int i=v,j=1;i<=n;i++){
		pai[j]=t[i];
		s++;
	}
	sort(pai+1,pai+s+1,cmdc);
	for(int i=1;i<=s;i++){
		for(int j=1;j<=3;j++){
			if(pai[i].a[j].o==3) continue;
			c[pai[i].a[j].o]++;
			ans+=pai[i].a[j].num;
			break; 
		}
	}
}
ll pa(int v){
	int s=0;
	memset(pai,0,sizeof(pai));
	for(int i=v,j=1;i<=n;i++){
		pai[j]=t[i];
		s++;
	}
	sort(pai+1,pai+s+1,pmda);
	for(int i=1;i<=s;i++){
		for(int j=1;j<=3;j++){
			if(pai[i].a[j].o==1) continue;
			c[pai[i].a[j].o]++;
			ans+=pai[i].a[j].num;
			break; 
		}
	}
}
ll pb(int v){
	int s=0;
	memset(pai,0,sizeof(pai));
	for(int i=v,j=1;i<=n;i++){
		pai[j]=t[i];
		s++;
	}
	sort(pai+1,pai+s+1,pmdb);
	for(int i=1;i<=s;i++){
		for(int j=1;j<=3;j++){
			if(pai[i].a[j].o==2) continue;
			c[pai[i].a[j].o]++;
			ans+=pai[i].a[j].num;
			break; 
		}
	}
}
ll pc(int v){
	int s=0;
	memset(pai,0,sizeof(pai));
	for(int i=v,j=1;i<=n;i++){
		pai[j]=t[i];
		s++;
	}
	sort(pai+1,pai+s+1,pmdc);
	for(int i=1;i<=s;i++){
		for(int j=1;j<=3;j++){
			if(pai[i].a[j].o==3) continue;
			c[pai[i].a[j].o]++;
			ans+=pai[i].a[j].num;
			break; 
		}
	}
}
void f(int r){
	memset(c,0,sizeof(c));
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++){
		cin>>t[i].a[1].num>>t[i].a[2].num>>t[i].a[3].num;
		t[i].a[1].o=1;
		t[i].a[2].o=2;
		t[i].a[3].o=3; 
		sort(t[i].a+1,t[i].a+3+1,opt);
	}
	sort(t+1,t+n+1,cmp);
	memset(c,0,sizeof(c));
	ll flag=0;
	for(int i=1;i<=n;i++){
		if(c[1]>=(n/2)||c[2]>=(n/2)||c[3]>=(n/2)){
			flag=i;
			break;
		}
		for(int j=1;j<=3;j++){
			c[t[i].a[j].o]++;
			ans+=t[i].a[j].num;
			break; 
		}
	}
	if(c[1]>=(n/2)){
		if(flag){
			ll ans1=ans,ans2=ans;
			ans1=fa(flag);
			ans2=pa(flag);
			ans+=max(ans1,ans2);
		}
	}
	else if(c[2]>=(n/2)){
		if(flag){
			ll ans1=ans,ans2=ans;
			ans1=fb(flag);
			ans2=pb(flag);
			ans+=max(ans1,ans2);
		}
	}
	else if(c[3]>=(n/2)){
		if(flag){
			ll ans1=ans,ans2=ans;
			ans1=fc(flag);
			ans2=pc(flag);
			ans+=max(ans1,ans2);
		}
	}
	cout<<ans<<"\n";
	ans=0;
	return ;
}
void dfs(int w,ll cnt){
	if(w==n+1){
		ans=max(ans,cnt);
		cout<<w<<" "<<cnt<<"\n";
		return ;
	}
	for(int i=1;i<=3;i++){
		int x=a[w][i];
		if(c[i]>=(n/2)) continue;
		c[i]++;
		cout<<w<<" "<<cnt<<" "<<i<<"\n";
		dfs(w+1,cnt+x);
		c[i]--;
	}
	return ;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int q;
	cin>>q;
	for(int y=0;y<q;y++){
		cin>>n;
		if(n<=10){
			memset(c,0,sizeof(c));
			memset(a,0,sizeof(a));
			for(int i=1;i<=n;i++){
				cin>>a[i][1]>>a[i][2]>>a[i][3];
			}
			ans=0;
			dfs(1,0);
			cout<<ans<<"\n";
		}
		else{
			f(0);
		}
	} 
	return 0;
} 