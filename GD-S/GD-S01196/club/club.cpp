#include<bits/stdc++.h>
using namespace std;
#define read(r1,r2) freopen(r1,"r",stdin);freopen(r2,"w",stdout);
const int N=1e5+5;
int T,n,a,b,c;
long long ans=0;
struct node1{
	int a,b,c;
	bool operator<(const node1 g) const{
		return min(a-b,a-c)>min(g.a-g.b,g.a-g.c);
	}
};
struct node2{
	int a,b,c;
	bool operator<(const node2 g) const{
		return min(b-a,b-c)>min(g.b-g.a,g.b-g.c);
	}
};
struct node3{
	int a,b,c;
	bool operator<(const node3 g) const{
		return min(c-b,c-a)>min(g.c-g.b,g.c-g.a);
	}
};
priority_queue<node1>q1;
priority_queue<node2>q2;
priority_queue<node3>q3;
int main(){
	read("club.in","club.out")
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;ans=0;
		//q1.clear();q2.clear();q3.clear();
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			if(a>=b&&a>=c){
				q1.push({a,b,c});
				if(q1.size()>n/2){
					a=q1.top().a;b=q1.top().b;c=q1.top().c;
					q1.pop();
					if(b>=c)q2.push({a,b,c});
					else q3.push({a,b,c});
				}
			}
			else if(b>=a&&b>=c){
				q2.push({a,b,c});
				if(q2.size()>n/2){
					a=q2.top().a;b=q2.top().b;c=q2.top().c;
					q2.pop();
					if(a>=c)q1.push({a,b,c});
					else q3.push({a,b,c});
				}
			}
			else {
				q3.push({a,b,c});
				if(q3.size()>n/2){
					a=q3.top().a;b=q3.top().b;c=q3.top().c;
					q3.pop();
					if(a>=b)q1.push({a,b,c});
					else q2.push({a,b,c});
				}
			}
		}
		while(!q1.empty()){
			ans+=q1.top().a;
			q1.pop();
		}
		while(!q2.empty()){
			ans+=q2.top().b;
			q2.pop();
		}
		while(!q3.empty()){
			ans+=q3.top().c;
			q3.pop();
		}
		cout<<ans<<"\n";
	}
}
