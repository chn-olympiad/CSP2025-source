#include<bits/stdc++.h>
using namespace std;
const int N=1e5+33;
int t;
struct cl{
	int a,b,c;
};
cl c[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		long long ans=0;
		int last;
		priority_queue<pair<int,int> > x,y,z;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>c[i].a>>c[i].b>>c[i].c;
			if(c[i].b>=c[i].a&&c[i].b>=c[i].c){
				ans+=c[i].b;
				y.push({-c[i].b,i});
			}
			if(c[i].a>=c[i].b&&c[i].a>=c[i].c){
				ans+=c[i].a;
				x.push({-c[i].a,i});
			}
			if(c[i].c>=c[i].b&&c[i].c>=c[i].a){
				ans+=c[i].c;
				z.push({-c[i].c,i});
			}
			int id=0;
			if(x.size()>(n/2)){
				id=x.top().second;
				x.pop();
				ans-=c[id].a;
				if(c[id].b>=c[id].c&&y.size()<(n/2)){
					ans+=c[id].b;
					y.push({-c[id].b,id});
				}else{
					ans+=c[id].c;
					z.push({-c[id].c,id});
				}
			}
			if(y.size()>(n/2)){
				id=y.top().second;
				y.pop();
				ans-=c[id].b;
				if(c[id].a>=c[id].c&&x.size()<(n/2)){
					ans+=c[id].a;
					x.push({-c[id].a,id});
				}else{
					ans+=c[id].c;
					z.push({-c[id].c,id});
				}
			}
			if(z.size()>(n/2)){
				id=z.top().second;
				z.pop();
				ans-=c[id].c;
				if(c[id].b>=c[id].a&&y.size()<(n/2)){
					ans+=c[id].b;
					y.push({-c[id].b,id});
				}else{
					ans+=c[id].a;
					z.push({-c[id].a,id});
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
