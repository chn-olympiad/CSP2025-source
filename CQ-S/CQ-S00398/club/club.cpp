#include<bits/stdc++.h>
using namespace std;
int n,t;
struct node{
	int a,b,c;
	int q1,q2,q3;
	int cmp1,cmp2,cmp3;
	bool q;
}m[10001];
bool aa(node x,node y){
	return x.cmp1>=y.cmp1;
}
bool bb(node x,node y){
	return x.cmp2>=y.cmp2;
}
bool cc(node x,node y){
	return x.cmp3>=y.cmp3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int ans;
		for(int i=1;i<=n;i++){
			m[i].q=1;
			scanf("%d%d%d",&m[i].a,&m[i].b,&m[i].c);
			if(m[i].a>m[i].b&&m[i].a>m[i].c){
				m[i].q1=1;
				m[i].cmp1=m[i].a;
				if(m[i].b>m[i].c){
					m[i].q2=2;
					m[i].cmp2=m[i].b;
					m[i].q3=3;
					m[i].cmp3=m[i].c;
				}else{
					m[i].q2=3;
					m[i].cmp2=m[i].c;
					m[i].q3=2;
					m[i].cmp3=m[i].b;
				}
			}
			if(m[i].b>m[i].c&&m[i].b>m[i].a){
				m[i].q1=2;
				m[i].cmp1=m[i].b;
				if(m[i].a>m[i].c){
					m[i].q2=1;
					m[i].cmp2=m[i].a;
					m[i].q3=3;
					m[i].cmp3=m[i].c;
				}else{
					m[i].q2=3;
					m[i].cmp2=m[i].c;
					m[i].q3=1;
					m[i].cmp3=m[i].a;
				}
			}
			if(m[i].c>m[i].a&&m[i].c>m[i].b){
				m[i].q1=3;
				m[i].cmp1=m[i].c;
				if(m[i].a>m[i].b){
					m[i].q2=1;
					m[i].cmp2=m[i].a;
					m[i].q3=2;
					m[i].cmp3=m[i].b;
				}else{
					m[i].q2=2;
					m[i].cmp2=m[i].b;
					m[i].q3=1;
					m[i].cmp3=m[i].a;
				}
			}
		}
		sort(m+1,m+1+n,aa);
		int num=0;
		for(int i=1;i<=n;i++){
			if(m[i].q){
				if(num+1<=n/2){
					ans+=m[i].cmp1;
					num++;
					m[i].q=0;
				}else{
					break;
				}
			}
		}
		num=0;
		sort(m+1,m+1+n,bb);
		for(int i=1;i<=n;i++){
			if(m[i].q){
				if(num+1<=n/2){
					ans+=m[i].cmp2;
					num++;
					m[i].q=0;
				}else{
					break;
				}
			}
		}
		num=0;
		sort(m+1,m+1+n,cc);
		for(int i=1;i<=n;i++){
			if(m[i].q){
				if(num+1<=n/2){
					ans+=m[i].cmp3;
					num++;
					m[i].q=0;
				}else{
					break;
				}
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
