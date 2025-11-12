#include<bits/stdc++.h> 
using namespace std;
const int N=2e5+50;
int T,n;
int x[5];
struct o{
	int idx,v;
}d[N];
bool cmp(o aa,o bb){
	return aa.v>=bb.v;
}
int main(){
	freopen("club.in","r",stdin); 
	freopen("club.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--){
		int ans=0,a,b,c;
		x[1]=0,x[2]=0,x[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			int m=min(min(a,b),c);
			ans+=m;
			a-=m,b-=m,c-=m;
			if(a==0){
				m=min(b,c);
				b-=m;
				c-=m;
			}
			else if(b==0){
				m=min(a,c);
				a-=m;
				c-=m;
			}
			else{
				m=min(a,b);
				a-=m;
				b-=m;
			}
			ans+=m;
			if(a>=b&&a>=c)d[i].idx=1,d[i].v=a;
			else if(b>=a&&b>=c)d[i].idx=2,d[i].v=b;
			else d[i].idx=3,d[i].v=c;
		}
		sort(d+1,d+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(x[d[i].idx]==n/2)continue;
			x[d[i].idx]++;
			ans+=d[i].v;
		}
		cout<<ans<<"\n";
	} 
}
