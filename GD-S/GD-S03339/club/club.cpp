#include<iostream>
#include<queue>
using namespace std;
template<typename T>
void rd(T &s){
	s=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)){
		s=(s<<1)+(s<<3)+(c-48);
		c=getchar();
	}
}
int T;
const int N=1e5+5;
int n;
struct stu{
	int a,b,c,mx,se;
	//分别表示对三个部门的满意度
	//满意度最大的那个部门的编号以及满意度 
	int cha;//满意度最大和第二大的差值 
	bool operator<(const stu &oth)const{
		return cha>oth.cha;
	}
}f[N];
priority_queue<stu> q[4];
int ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	rd(T);
	while(T--){
		rd(n);
		int big=0;
		ans=0;
		for(int i=1;i<=n;i++){
			rd(f[i].a),rd(f[i].b),rd(f[i].c);
			big=max(f[i].a,max(f[i].b,f[i].c));
			if(big==f[i].a){
				f[i].mx=1;
				if(f[i].b>=f[i].c){
					f[i].cha=f[i].a-f[i].b;
					f[i].se=2;
				}
				else{
					f[i].cha=f[i].a-f[i].c;
					f[i].se=3;
				}
			}else if(big==f[i].b){
				f[i].mx=2;
				if(f[i].a>=f[i].c){
					f[i].cha=f[i].b-f[i].a;
					f[i].se=1;
				}
				else{
					f[i].cha=f[i].b-f[i].c;
					f[i].se=3;
				}
			}else{
				f[i].mx=3;
				if(f[i].a>=f[i].b){
					f[i].cha=f[i].c-f[i].a;
					f[i].se=1;
				}
				else{
					f[i].cha=f[i].c-f[i].b;
					f[i].se=2;
				}
			}
		}
		for(int i=1;i<=n;i++){
			int cur=f[i].mx;
			if(q[cur].size()==(n>>1)){//已经满人了 
				stu x=q[cur].top();
				if(x.cha<f[i].cha){//替换 
					q[cur].pop();
					q[cur].push(f[i]);
					q[x.se].push(x);
				}else{
					q[f[i].se].push(f[i]);
				}
			}else{
				q[cur].push(f[i]);
			}
		}
		while(!q[1].empty()){
			stu u=q[1].top();
			q[1].pop();
			ans+=u.a;
		}
		while(!q[2].empty()){
			stu u=q[2].top();
			q[2].pop();
			ans+=u.b;
		}
		while(!q[3].empty()){
			stu u=q[3].top();
			q[3].pop();
			ans+=u.c;
		}
		printf("%d\n",ans);
	} 
	return 0;
} 
