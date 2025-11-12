#include<bits/stdc++.h>

using namespace std;

int n,t,a,b,c,an,bn,cn,sum;

struct st{
	int m1,m2,m3;
	int p1,p2,p3;
	int cj;
}x[100010];
bool cmp(st q,st p){
	return q.cj>=p.cj;
	}
inline void tj(int o){
	for(int i=1;i<=n;i++){
		if(x[i].p1==1){
			if(an<n/2){
				sum += x[i].m1;
				an++;
				}
			else{
				sum += x[i].m2;
				if(x[i].p2==2) bn++;
				if(x[i].p2==3) cn++;
				}
		}
		if(x[i].p1==2){
			if(bn<n/2){
				sum += x[i].m1;
				bn++;
				}
			else{
				sum += x[i].m2;
				if(x[i].p2==1) an++;
				if(x[i].p2==3) cn++;
				}
		}
		if(x[i].p1==3){
			if(cn<n/2){
				sum += x[i].m1;
				cn++;
				}
			else{
				sum += x[i].m2;
				if(x[i].p2==1) an++;
				if(x[i].p2==2) bn++;
				}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int k=1;k<=t;k++){
		an=0,bn=0,cn=0;
		sum = 0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a,&b,&c);
			if(a>b){
				if(a>c){
					if(b>c){
						x[i].m1 = a,x[i].m2 = b,x[i].m3 = c;
						x[i].p1 = 1;x[i].p2 = 2,x[i].p3 = 3;
					}else{
						x[i].m1 = a,x[i].m2 = c,x[i].m3 = b;
						x[i].p1 = 1;x[i].p2 = 3,x[i].p3 = 2;
						}
				}else{
						x[i].m1 = c,x[i].m2 = a,x[i].m3 = b;
						x[i].p1 = 3;x[i].p2 = 1,x[i].p3 = 2;
					}
			}else{
				if(a>c){
						x[i].m1 = b,x[i].m2 = a,x[i].m3 = c;
						x[i].p1 = 2;x[i].p2 = 1,x[i].p3 = 3;
					}else{
						x[i].m1 = b,x[i].m2 = c,x[i].m3 = a;
						x[i].p1 = 2;x[i].p2 = 1,x[i].p3 = 3;
						}
				}
			if(c>=b&&b>=a){
						x[i].m1 = c,x[i].m2 = b,x[i].m3 = a;
						x[i].p1 = 3;x[i].p2 = 2,x[i].p3 = 1;
			}
			x[i].cj = x[i].m1-x[i].m2;
		}
			//---------------------------------------------		
			sort(x+1,x+n+1,cmp);
			tj(114514);
		printf("%d",sum);
		cout<<endl;
	}
	return 0;
}
