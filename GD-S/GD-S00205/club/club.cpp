#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N][4],ans,cnt2,cnt3;
struct node{
	int dis2,dis3,d2,d3;
}d[N];
priority_queue<int>q2,q3;
bool cmp(node a,node b){
	return max(a.dis2,a.dis3)>max(b.dis2,b.dis3);
}
inline void mian(){
	cin>>n;cnt2=cnt3=ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		ans+=a[i][1];
		d[i].dis2=a[i][2]-a[i][1];
		d[i].dis3=a[i][3]-a[i][1];
		d[i].d2=d[i].dis3-d[i].dis2;//xiangfanshu
		d[i].d3=d[i].dis2-d[i].dis3;
	}sort(d+1,d+1+n,cmp);//cout<<ans<<'\n';
//	for(int i=1;i<=n;i++){
//		cout<<d[i].dis2<<' '<<d[i].dis3<<' '<<d[i].d2<<' '<<d[i].d3<<'\n';
//	}
	for(int i=1;i<=n/2;i++){
		if(d[i].dis2>d[i].dis3)ans+=d[i].dis2,cnt2++,q2.push(d[i].d2);
		else ans+=d[i].dis3,cnt3++,q3.push(d[i].d3);
//		cout<<ans<<' '<<cnt2<<' '<<cnt3<<'\n';
	}
	for(int i=n/2+1;i<=n;i++){
		if(max(d[i].dis2,d[i].dis3)>0){
			if(d[i].dis2>d[i].dis3){
//				cout<<i<<" 2 ";
				if(cnt2<n/2)ans+=d[i].dis2,cnt2++,q2.push(d[i].d2);
				else{
					int tmp=-q2.top();
					if(tmp<(-d[i].d2)&&d[i].dis2-tmp>0){
						ans-=tmp,ans+=d[i].dis2,q2.pop(),q2.push(d[i].d2),cnt3++;
					}
				}
			}
			else{
//				cout<<i<<" 3 ";
				if(cnt3<n/2)ans+=d[i].dis3,cnt3++,q3.push(d[i].d3);
				else{
					int tmp=-q3.top();
					if(tmp<(-d[i].d3)&&d[i].dis3-tmp>0){
						ans-=tmp,ans+=d[i].dis3,q3.pop(),q3.push(d[i].d3),cnt2++;
					}
				}
			}
		}else break;//cout<<ans<<' '<<cnt2<<' '<<cnt3<<"*\n";
	}cout<<ans<<'\n';
	q2=priority_queue<int>();
	q3=priority_queue<int>();
}
int TT;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>TT;while(TT--)mian();
	return 0;
}/*
1
10
6839 5455 15586       3
11767 12919 2643      2
13775 8904 19938	  3
13717 11997 15170	  1
13707 2404 17497      3
3471 2462 8073        3
18467 14346 18663     1
13582 4839 15785      1
11875 7476 12308      1
8568 3134 18522       3

*/
