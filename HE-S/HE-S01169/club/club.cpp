#include <bits/stdc++.h>
using namespace std;
int T;
int n; 
int maxn=0;
struct edge{
	int a,b,c;
}q[100005];
bool cmp(edge x,edge y){
	if(x.a==y.a){
		if(x.b==y.b){
			return x.c<y.c;
		}
		else{
			return x.b<y.b;
		}
	}
	else{
		return x.a<y.a;		
	}
}
queue<int> g1,g2,g3;
int maxx(){
	maxn=0; 
	int x=1;
	int x2,x3;
	for(int i=1;i<=n;i++){
		g1.push(q[i].a);
		maxn+=q[i].a;
		if(g1.size()>n/2){
			if(q[i].a>=q[x].a){
				if(q[x].b>=q[i].b){
					g1.pop();
					g2.push(q[x].b);
					maxn-=q[x].a;
					maxn+=q[x].b;
					if(g2.size()<=n/2&&g2.size()>1){
						if(q[x].b>q[x2].b){
							if(q[x2].c-q[x2].b>0){
							maxn-=q[x2].b;
							maxn+=q[x2].c;
							g3.push(q[x2].c);
							x3=x2;
							x2=i;
							}	
						}
					}
					x2=x;
					x++;
				}
				else{
					if(q[i].a-q[x].a<q[i].b-q[x].b){
						maxn-=q[i].a;
						g2.push(q[i].b);
						maxn+=q[i].b;
						g1.pop();
						x2=i;
						x++;
					}
				}
			}
		}	
	}
	while(g1.size()!=0){
		g1.pop();
	}
	while(g2.size()!=0){
		g2.pop();
	}
	while(g2.size()!=0){
		g2.pop();
	}
}
int main(){
	freeopen("club.in","r",stdin);
	freeoprn("club.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>q[j].a>>q[j].b>>q[j].c;
		}
		sort(q+1,q+n+1,cmp);
		maxx();
		cout<<maxn<<"\n";
	}
} 
