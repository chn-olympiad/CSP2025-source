#include <bits/stdc++.h>
using namespace std;

int n;

struct person{
	int a1,a2,a3,best,atak,ato,num;
}p[100010];
int b[4];

bool cmp(person x,person y){
	return x.atak<y.atak;
}

bool back(person x,person y){
	return x.num<y.num;
}

void solve(int v){
	sort(p+1,p+n+1,cmp);
	int cnt=0;
	for(int i=1;i<=n&&b[v]>n/2;i++){
		if(p[i].best==v){
			p[i].best=p[i].ato;
			if(p[i].best+p[i].ato==3){
				p[i].ato=3;
				if(p[i].best==1) p[i].atak=p[i].a1-p[i].a3;
				else p[i].atak=p[i].a2-p[i].a3;
			}else if(p[i].best+p[i].ato==4){
				p[i].ato=2;
				if(p[i].best==1) p[i].atak=p[i].a1-p[i].a2;
				else p[i].atak=p[i].a3-p[i].a2;
			}else{
				p[i].ato=1;
				if(p[i].best==3) p[i].atak=p[i].a3-p[i].a1;
				else p[i].atak=p[i].a2-p[i].a1;
			}
			b[v]--;b[p[i].best]++;
		}
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;cin>>T;
	while(T--){
		memset(p,0,sizeof(p));
		memset(b,0,sizeof(b));
		cin>>n;
		for(int i=1;i<=n;i++){
			p[i].num=i;
			cin>>p[i].a1>>p[i].a2>>p[i].a3;
			if(p[i].a1>=p[i].a2&&p[i].a1>=p[i].a3){
				p[i].best=1;b[1]++;
				if(p[i].a2>p[i].a3) p[i].atak=p[i].a1-p[i].a2,p[i].ato=2;
				else p[i].atak=p[i].a1-p[i].a3,p[i].ato=3;
			}else if(p[i].a2>=p[i].a1&&p[i].a2>=p[i].a3){
				p[i].best=2;b[2]++;
				if(p[i].a1>p[i].a3) p[i].atak=p[i].a2-p[i].a1,p[i].ato=1;
				else p[i].atak=p[i].a2-p[i].a3,p[i].ato=3;
			}else{
				p[i].best=3;b[3]++;
				if(p[i].a2>p[i].a1) p[i].atak=p[i].a3-p[i].a2,p[i].ato=2;
				else p[i].atak=p[i].a3-p[i].a1,p[i].ato=1;
			}
		}
		if(b[1]>n/2) solve(1);
		if(b[2]>n/2) solve(2);
		if(b[3]>n/2) solve(3);
		sort(p+1,p+n+1,back);
		int ans=0;
		for(int i=1;i<=n;i++){
			if(p[i].best==1) ans+=p[i].a1;
			else if(p[i].best==2) ans+=p[i].a2;
			else ans+=p[i].a3;
		}
		
		cout<<ans<<'\n';
	}
	return 0;
}
