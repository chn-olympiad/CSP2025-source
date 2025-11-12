#include<bits/stdc++.h>
using namespace std;
int t,n,ans,b[5],c[4];
int check[200100];
struct ppp{
	int a1,a2,a3;
	int num;
	int pm;
	int pos[4];
	int pn;
	int pnn;
}p[200010];
bool cmp(ppp a,ppp b){
	if(a.pm - a.pn == b.pm - b.pn) return (a.pn - a.pnn) > (b.pn - b.pnn);
	return (a.pm - a.pn) > (b.pm - b.pn);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		
		scanf("%d",&n);
		int top = n / 2;
		for(int i = 1 ; i <= n ; i++){
			scanf("%d%d%d",&p[i].a1,&p[i].a2,&p[i].a3);
			p[i].num = i;
			p[i].pm = max(p[i].a1 , p[i].a2);
			p[i].pm = max(p[i].pm , p[i].a3);
			if(p[i].pm == p[i].a1) p[i].pos[1] = 1;
			if(p[i].pm == p[i].a2) p[i].pos[1] = 2;
			if(p[i].pm == p[i].a3) p[i].pos[1] = 3;
			if(p[i].pos[1] == 1) {
				p[i].pn = max(p[i].a2,p[i].a3);
				if(p[i].pn == p[i].a2){
					p[i].pos[2] = 2;
					p[i].pos[3] = 3;
				} 
				else{
					p[i].pos[2] = 3;
					p[i].pos[3] = 2;
				}
				p[i].pnn = min(p[i].a2,p[i].a3);
			}
			if(p[i].pos[1] == 2) {
				p[i].pn = max(p[i].a1,p[i].a3);
				if(p[i].pn == p[i].a1){
					p[i].pos[2] = 1;
					p[i].pos[3] = 3;
				} 
				else{
					p[i].pos[2] = 3;
					p[i].pos[3] = 1;
				}
				p[i].pnn = min(p[i].a1,p[i].a3);
			}
			if(p[i].pos[1] == 3){
				p[i].pn = max(p[i].a2,p[i].a1);
				if(p[i].pn == p[i].a2){
					p[i].pos[2] = 2;
					p[i].pos[3] = 1;
				} 
				else{
					p[i].pos[2] = 1;
					p[i].pos[3] = 2;
				}
				p[i].pnn = min(p[i].a2,p[i].a1);
			} 
		}
		
		
		sort(p+1,p+n+1,cmp);
		for(int i = 1; i <= n ; i++){
			if(b[p[i].pos[1]] < top){
				b[p[i].pos[1]]++;
				ans += p[i].pm;
				check[i] = p[i].pm;
				c[p[i].pos[1]] = i;
			} 
			else if(b[p[i].pos[2]] < top){
				b[p[i].pos[2]]++;
				ans += p[i].pn;
				check[i] = p[i].pn;
				c[p[i].pos[2]] = i;
			}
			else{
				b[p[i].pos[3]]++;
				ans += p[i].pnn;
				check[i] = p[i].pnn;
				c[p[i].pos[3]] = i;
			}
		}
		printf("%d\n",ans);
		
		
		for(int i = 1; i <= n; i++){
			check[i] = 0;
			p[i].a1 = 0;
			p[i].a2 = 0;
			p[i].a3 = 0;
			p[i].num = 0;
			p[i].pm = 0;
			p[i].pn = 0;
			p[i].pnn = 0;
			for(int j=1;j<=3;j++) p[i].pos[j]=0;
		}
		ans = 0;
		b[1] = 0;
		b[2] = 0;
		b[3] = 0;
	}
	
	
	
	
	
	return 0;
}


