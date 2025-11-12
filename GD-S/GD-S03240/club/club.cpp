#include <bits/stdc++.h>

using namespace std;
const int N = 1e5+100;

struct qqq{
	int a,b,c;
}dt[N];
bool cmp1(const qqq& a,const qqq& b){
	return a.a > b.a;
}
bool cmp2(const qqq& a,const qqq& b){
	return a.b < b.b;
}
bool cmp3(const qqq& a,const qqq& b){
	return a.c < b.c;
}

struct edge{
	int d,id;
};
class dui{
	static const int DN=(N>>1)+10;
	edge l[DN];
	int tp;
	void up(int i){
		for(;i>1;i>>=1){
			if(l[i>>1].d < l[i].d) return;
			swap(l[i>>1],l[i]);
		}
	}
	void down(int i){
		for(int k=i<<1;k<=tp;){
			if(k+1<=tp && l[k+1].d < l[k].d) k+=1;
			if(l[i].d < l[k].d) return;
			swap(l[i],l[k]);
			i=k;
			k<<=1;
		}
	}
public:
	dui():tp(0){
		memset(l,0,sizeof(l));
	}
	void init(){
		tp=0;
	}
	void push(int data ,int id){
		++tp;
		l[tp].d =data;
		l[tp].id = id;
		up(tp);
	}
	void pop(){
		swap(l[1],l[tp]);
		tp--;
		down(1);
	}
	edge top(){
		return l[1];
	}
	int size(){
		return tp;
	}
}d1,d2,d3;


long long s1,s2,s3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	int T;
	scanf("%d",&T);
	for(int n,n2;T;--T){
		s1=0;s2=0;s3=0;
		d1.init();d2.init();d3.init();
		scanf("%d",&n);n2=n/2;
		for(int i = 1;i<=n;i++){
			scanf("%d%d%d",&dt[i].a,&dt[i].b,&dt[i].c);
		if(dt[i].a > dt[i].b){
//printf(" >s1=%lld s2=%lld\n",s1,s2);
			if(d1.size()>=n2){
				int ti=d1.top().id;
				if(dt[i].a + dt[ti].b > dt[ti].a){
//printf(" !>\n");
					d1.pop();
					s1-=dt[ti].a;
					d1.push(dt[i].a,i);
					s1+=dt[i].a;
					d2.push(dt[ti].b,ti);
					s2+=dt[ti].b;
					continue;
				}
				d2.push(dt[i].b,i);
				s2+=dt[i].b;
			}
			else{
				d1.push(dt[i].a,i);
				s1+=dt[i].a;
			}
		}else{
//printf(" <s1=%lld s2=%lld\n",s1,s2);
			if(d2.size()>=n2){
				int ti=d2.top().id;
				if(dt[i].b + dt[ti].a > dt[ti].b){
//printf(" !<\n");
					d2.pop();
//printf("???");
					s2-=dt[ti].b;
					d2.push(dt[i].b,i);
					s2+=dt[i].b;
					d1.push(dt[ti].a,ti);
					s1+=dt[ti].a;
					continue;
				}
				d1.push(dt[i].a,i);
				s1+=dt[i].a;
			}
			else{
				d2.push(dt[i].b,i);
				s2+=dt[i].b;
			}
		}
		}
		printf("%lld\n",s1+s2);
	}
	
	
	return 0;
}
