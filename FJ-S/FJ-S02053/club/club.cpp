#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int t,n;
struct node{
	int my,wz;
}e[10];
struct jgt{
	int a,b,c,aw,bw,cw;
}f[N];
deque<int> q[10],q1[10],q2[10],q3[10];
bool cmp(node q,node p){
	return q.my>p.my;
}
bool cmp1(jgt u,jgt v){
	return u.a>v.a;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>e[j].my;
				e[j].wz=j;
			}
			sort(e+1,e+4,cmp);
			f[i].a=e[1].my;
			f[i].b=e[2].my;
			f[i].c=e[3].my;
			f[i].aw=e[1].wz;
			f[i].bw=e[2].wz;
			f[i].cw=e[3].wz;
		}
		sort(f+1,f+n+1,cmp1);
		int sum=0;
		for(int i=1;i<=n;i++){
			int g=f[i].aw;
			int h=f[i].bw;
			int l=f[i].cw;
			if(q[g].size()<=n/2-1){
				q[g].push_back(f[i].a);
				q1[g].push_back(f[i].b);
				q2[g].push_back(f[i].bw);
				q3[g].push_back(i);
				sum+=f[i].a;
			}else if(q[g].size()&&sum-q[g].back()+f[i].a+q1[g].back()>sum){
				if(q[q2[g].back()].size()<=n/2-1){
					sum=sum-q[g].back()+f[i].a+q1[g].back();
					q[q2[g].back()].push_back(q1[g].back());
					if(q1[g].back()==f[q3[g].back()].b){
						q1[q2[g].back()].push_back(f[q3[g].back()].c);
						q2[q2[g].back()].push_back(f[q3[g].back()].cw);
						q3[q2[g].back()].push_back(q3[g].back());
					}else{
						q1[q2[g].back()].push_back(-1);
						q2[q2[g].back()].push_back(0);
						q3[q2[g].back()].push_back(q3[g].back());
					}
					q[g].pop_back();
					q1[g].pop_back();
					q2[g].pop_back();
					q3[g].pop_back();
					q[g].push_back(f[i].a);
					q1[g].push_back(f[i].b);
					q2[g].push_back(f[i].bw);
					q3[g].push_back(i);
				}
			}else if(q[h].size()<=n/2-1){
				q[h].push_back(f[i].b);
				q1[h].push_back(f[i].c);
				q2[h].push_back(f[i].cw);
				q3[h].push_back(i);
				sum+=f[i].b;
			}else if(q[h].size()&&sum-q[h].back()+f[i].b+q1[h].back()>sum){
				if(q[q2[h].back()].size()<=n/2-1){
					sum=sum-q[h].back()+f[i].b+q1[h].back();
					q[q2[h].back()].push_back(q1[h].back());
					if(q1[h].back()==f[q3[h].back()].b){
						q1[q2[h].back()].push_back(f[q3[h].back()].c);
						q2[q2[h].back()].push_back(f[q3[h].back()].cw);
						q3[q2[h].back()].push_back(q3[h].back());
					}else{
						q1[q2[h].back()].push_back(-1);
						q2[q2[h].back()].push_back(0);
						q3[q2[h].back()].push_back(q3[h].back());
					}
					q[h].pop_back();
					q1[h].pop_back();
					q2[h].pop_back();
					q3[h].pop_back();
					q[h].push_back(f[i].b);
					q1[h].push_back(f[i].c);
					q2[h].push_back(f[i].cw);
					q3[h].push_back(i);
				}
			}else{
				q[l].push_back(f[i].c);
				q1[l].push_back(-1);
				q2[l].push_back(0);
				q3[l].push_back(i);
				sum+=f[i].c;
			}
		}
		cout<<sum<<endl;
		for(int i=1;i<=3;i++){
			while(q[i].size()){
				q[i].pop_back();
			}
			while(q1[i].size()){
				q1[i].pop_back();
			}
			while(q2[i].size()){
				q2[i].pop_back();
			}
			while(q3[i].size()){
				q3[i].pop_back();
			}
		}
		
	}
	return 0;
}