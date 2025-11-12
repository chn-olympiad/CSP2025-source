#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int cnt[5];
struct node{
	int a,b,c;
	int id,maxx;
}g[N];
struct stu{
	int id,maxx;
	int cid,cha;
}x[N];

bool cmp1(node p,node q){
	return p.a>q.a;
}
bool cmp2(stu p,stu q){
	if(p.maxx==q.maxx){
		return p.cha<q.cha;
	}
	return p.maxx>q.maxx;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		bool flag0=0;
		for(int i=1;i<=n;i++){
			cin>>g[i].a>>g[i].b>>g[i].c;
			if(g[i].b==0&&g[i].c==0)continue;
			else flag0=1;
			g[i].id=i;
			x[i].maxx=max(g[i].a,max(g[i].b,g[i].c));
			if(x[i].maxx==g[i].a){
				x[i].cha=x[i].maxx-max(g[i].b,g[i].c);
				if(max(g[i].b,g[i].c)==g[i].b)x[i].cid=2;
				else x[i].cid=3;
				x[i].id=1;
			}
			else if(x[i].maxx==g[i].b){
				x[i].cha=x[i].maxx-max(g[i].a,g[i].c);
				if(max(g[i].a,g[i].c)==g[i].a)x[i].cid=1;
				else x[i].cid=3;
				x[i].id=2;
			}
			else if(x[i].maxx==g[i].c){
				x[i].cha=x[i].maxx-max(g[i].a,g[i].b);
				if(max(g[i].a,g[i].b)==g[i].a)x[i].cid=1;
				else x[i].cid=2;
				x[i].id=3;
			}
		}
		int ans=0;
		if(n==2){
			ans=max(ans,g[1].a+g[2].b);
			ans=max(ans,g[1].a+g[2].c);
			ans=max(ans,g[1].b+g[2].c);
			ans=max(ans,g[1].b+g[2].a);
			ans=max(ans,g[1].c+g[2].a);
			ans=max(ans,g[1].c+g[2].b);
			cout<<ans<<"\n";
			continue;
		}
		if(flag0==0){
			sort(g+1,g+n+1,cmp1);
			for(int i=1;i<=n/2;i++)ans+=g[i].a;
			cout<<ans<<"\n";
			continue;
		}
		sort(x+1,x+n+1,cmp2);
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			cnt[x[i].id]++;
			if(cnt[x[i].id]<=n/2)ans+=x[i].maxx;
			else{
				ans+=(x[i].maxx-x[i].cha);
				cnt[x[i].id]--;cnt[x[i].cid]++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}