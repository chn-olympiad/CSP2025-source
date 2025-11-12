//club
#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int,pair<int,bool> > pii;
int n,a[100010],b[100010],c[100010];
int ans;
priority_queue<pii> pq;
pii p;
bool v[100010];
int cnt,x,y;
int read(){
	char c;
	while(!isdigit(c=getchar()));
	int k=c-'0';
	while(isdigit(c=getchar())) k=k*10+c-'0';
	return k;
}
void slv(){
	n=read(); 
	ans=x=y=0;
	cnt=n;
	while(!pq.empty()) pq.pop();
	for(int i=1;i<=n;i++){
		a[i]=read(),b[i]=read(),c[i]=read();
		ans+=a[i];
		v[i]=0;
		pq.push({b[i]-a[i],{i,1}});
		pq.push({c[i]-a[i],{i,0}});
	}
	while(cnt>n/2){
		p=pq.top();pq.pop();
		if(v[p.s.f]) continue;
		v[p.s.f]=1,cnt--;
		ans+=p.f;
		if(p.s.s) x++;
		else y++;
	}
	while(!pq.empty()&&pq.top().f>0){
		p=pq.top();pq.pop();
		if(v[p.s.f]) continue;
		if(p.s.s){
			if(x<n/2){
				ans+=p.f,x++;
				v[p.s.f]=1;
			};
		}else if(y<n/2){
			ans+=p.f,y++;
			v[p.s.f]=1;
		}
	}
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--) slv();
	return 0;
} 
