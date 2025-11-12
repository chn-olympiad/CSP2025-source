#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int k,n;
struct mem{
	int f,s,t,c1,c2,c3;
}m[maxn];
bool cmp1(const mem &x1,const mem &x2){
	return x1.f-x1.s>x2.f-x2.s;
}
bool cmp2(const mem &x1,const mem &x2){
	return x1.s-x1.t>x2.s-x2.t;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>k;
	while(k--){
		cin>>n;
		vector<mem>v;
		for(int i=1;i<=n;i++){
			int a,b,c,f,s,t,c1,c2,c3;
			cin>>a>>b>>c;
			if(a>=b&&a>=c){
				f=a;
				c1=1;
				if(b>=c){
					s=b;
					c2=2;
					t=c;
					c3=3;
				}else{
					s=c;
					c2=3;
					t=b;
					c3=2;
				}
			}else if(b>=a&&b>=c){
				f=b;
				c1=2;
				if(a>=c){
					s=a;
					c2=1;
					t=c;
					c3=3;
				}else{
					s=c;
					c2=3;
					t=a;
					c3=1;
				}
			}else{
				f=c;
				c1=3;
				if(a>=b){
					s=a;
					c2=1;
					t=b;
					c3=2;
				}else{
					s=b;
					c2=2;
					t=a;
					c3=1;
				}
			}
			m[i].f=f;
			m[i].s=s;
			m[i].t=t;
			m[i].c1=c1;
			m[i].c2=c2;
			m[i].c3=c3;
		}
		sort(m+1,m+n+1,cmp1);
		long long ans=0;
		int sz[4];
		sz[1]=sz[2]=sz[3]=n>>1;
		for(int i=1;i<=n;i++){
			if(sz[m[i].c1]){
				ans+=m[i].f;
				sz[m[i].c1]--;
			}else{
				v.push_back(m[i]);
			}
		}
		sort(v.begin(),v.end(),cmp2);
		for(vector<mem>::iterator it=v.begin();it!=v.end();it++){
			if(sz[it->c2]){
				ans+=it->s;
				sz[it->c2]--;
			}else{
				ans+=it->t;
				sz[it->c3]--;
			}
		}
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
