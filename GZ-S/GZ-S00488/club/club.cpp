//GZ-S00488 遵义市第四中学 雍大有 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100005;
ll T,n,lim,ans,top[5],que[N][5],a[N][5],seca[N];
bitset<N> vis;
vector<pair<ll,ll> > Q;
void f_read(ll &x){
	x=0;
	bool w=0;
	char ch=0;
	while(!isdigit(ch)){
		if(ch=='-')w=1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch-'0');
		ch=getchar();
	}
	if(w)x=-x;
}
void f_write(ll x){
	static int sta[65];
	int top=0;
	if(x<0){
		x=-x;
		putchar('-');
	}
	do{
		sta[top++]=x%10;
		x/=10;
	}while(x);
	while(top)putchar(sta[--top]+'0');
}
void solve(ll pla){
	for(int i=1;i<=top[pla];++i){
		ll u=que[i][pla];
		Q.push_back(make_pair(a[u][pla]-a[u][seca[u]],u));
	}
	sort(Q.begin(),Q.end());
	ll t=0;
	while(top[pla]>lim){
		ll u=Q[t].second,w=Q[t].first;
		++t;
		int chag=seca[u];
		ans-=w,++top[chag],--top[pla];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	f_read(T);
	while(T--){
		ans=0,lim=0;
		top[1]=top[2]=top[3]=top[4]=0;
		Q.clear();
		f_read(n);
		lim=(n>>1);
		for(int i=1;i<=n;++i){
			f_read(a[i][1]);
			f_read(a[i][2]);
			f_read(a[i][3]);
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				que[++top[1]][1]=i,ans+=a[i][1];
				seca[i]=(a[i][2]>=a[i][3])?2:3;
			}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				que[++top[2]][2]=i,ans+=a[i][2];
				seca[i]=(a[i][1]>=a[i][3])?1:3;
			}else{
				que[++top[3]][3]=i,ans+=a[i][3];
				seca[i]=(a[i][1]>=a[i][2])?1:2;
			}
		}
		if(top[1]<=lim&&top[2]<=lim&&top[3]<=lim){
			f_write(ans);
			putchar('\n');
			continue;
		}
		if(top[1]>lim)solve(1);
		else if(top[2]>lim)solve(2);
		else if(top[3]>lim)solve(3);
		f_write(ans);
		putchar('\n');
	}
	return 0;
}
