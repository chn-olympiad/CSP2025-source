#include "bits/stdc++.h"
using namespace std;
//#define ll long long
const int N=1e5+5;
int t,n;
long long ans=0;
struct Data{
	int a,b,c;
	int ma,mb,mc;
}e[N];
int cmp(Data x,Data y){
	if(x.ma!=y.ma) return x.ma>y.ma;
	if(x.mc!=y.mc) return x.mc>y.mc;
	return x.mb>y.mb;
}//a little difficult(chouxiang)
int cnt[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		cnt[1]=cnt[2]=cnt[3]=ans=0;
		priority_queue<pair<int,int> > q[4];
		scanf("%d",&n);
		int ll=n/2;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c);
			e[i].ma=max(e[i].a,max(e[i].b,e[i].c));
			e[i].mb=min(e[i].a,min(e[i].b,e[i].c));
			e[i].mc=e[i].a==e[i].ma?max(e[i].b,e[i].c):
			        e[i].b==e[i].ma?max(e[i].a,e[i].c):
			                        max(e[i].a,e[i].b);
		}
		sort(e+1,e+1+n,cmp);
		for(int i=1;i<=n;i++){
			int pl=e[i].a==e[i].ma?1:e[i].b==e[i].ma?2:3;
			if(cnt[pl]==ll){
				if(q[pl].top().first<e[i].ma-e[i].mc){
					cnt[pl]++;
					ans+=e[i].ma+e[q[pl].top().second].mc-e[q[pl].top().second].ma;
//					cout<<"#1# "<<ans<<endl;
					q[pl].pop();
					q[pl].push({e[i].ma-e[i].mc,i});
				} else{
					pl=e[i].a==e[i].mb?1:e[i].b==e[i].mb?2:3;
					cnt[pl]++;
					ans+=e[i].mc;
					q[pl].push({e[i].mc-e[i].mb,i});
//					cout<<"#2# "<<ans<<endl;
				}
			} else{
				cnt[pl]++;
				ans+=e[i].ma;
				q[pl].push({e[i].ma-e[i].mc,i});
//				cout<<"#3# "<<ans<<endl;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*贪心?
1.意愿优先 
2.选完了的入堆，当某部门人数封顶时，查找该部门所包含人员，他调剂 
3.调剂满足：结果的总意愿值>原来的值
4.O(n)，其实自己也不确定时间复杂度 
5.Good Luck! 

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
