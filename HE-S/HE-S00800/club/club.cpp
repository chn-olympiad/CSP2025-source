#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t;
int n,cnt;
int club[10];
long long ans;
struct node{
	int a,b,c;
	int m1,m2,m3;
	int id1,id2,id3;
}x[N];
bool cmp(node z,node y){
	if(z.m1==y.m1){
		if(z.m2==z.m2){
			return z.m3>y.m3;
		}
		return z.m2>y.m2;
	}
	return z.m1>y.m1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;++i){
		scanf("%d",&n);
		ans=0;
		cnt=n/2;
		for(int j=1;j<=n;++j){
			scanf("%d%d%d",&x[j].a,&x[j].b,&x[j].c);
			if(x[j].a>=x[j].b&&x[j].a>=x[j].c){
				x[j].m1=x[j].a;
				x[j].id1=1;
				if(x[j].b>=x[j].c){
					x[j].m2=x[j].b;
					x[j].m3=x[j].c;
					x[j].id2=2;
					x[j].id3=3;
				}
				else{
					x[j].m3=x[j].b;
					x[j].m2=x[j].c;
					x[j].id3=2;
					x[j].id2=3;
				}
			}
			else if(x[j].b>=x[j].a&&x[j].b>=x[j].c){
				x[j].m1=x[j].b;
				x[j].id1=2;
				if(x[j].a>=x[j].c){
					x[j].m2=x[j].a;
					x[j].m3=x[j].c;
					x[j].id2=1;
					x[j].id3=3;
				}
				else{
					x[j].m3=x[j].a;
					x[j].m2=x[j].c;
					x[j].id3=1;
					x[j].id2=3;
				}
			}
			else{
				x[j].m1=x[j].c;
				x[j].id1=3;
				if(x[j].a>=x[j].b){
					x[j].m2=x[j].a;
					x[j].m3=x[j].b;
					x[j].id3=2;
					x[j].id2=1;
				}
				else{
					x[j].m3=x[j].a;
					x[j].m2=x[j].b;
					x[j].id3=1;
					x[j].id2=2;
				}
			}
		}
		sort(x+1,x+n+1,cmp);
		for(int j=1;j<=n;++j){
			if(club[x[j].id1]<=cnt){
				++club[x[j].id1];
				ans+=x[j].m1;
			}
			else if(club[x[j].id2]<=cnt){
				++club[x[j].id2];
				ans+=x[j].m2;
			}
			else{
				++club[x[j].id3];
				ans+=x[j].m3;
			}
		}
		printf("%ld\n",ans);
		club[1]=0;
		club[2]=0;
		club[3]=0;
	}
	return 0;
}
// q.7
//~l2
//ÈË½ÜµØÁé
//5 4 4 5
