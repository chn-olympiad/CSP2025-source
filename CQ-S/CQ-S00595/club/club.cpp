/*
简单贪心
注意多组数据的初始化问题 
总和long long 
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=100005; 
struct club{
	int a,id;
};
struct node{
	club p[4];
	bool b;
}peo[N];
bool cmp(club a,club b){
	return a.a>b.a;
}
bool cmp1(node a,node b){
	if(a.p[1].a-a.p[2].a==b.p[1].a-b.p[2].a){
		return a.p[1].a>b.p[1].a;
	}
	return a.p[1].a-a.p[2].a>b.p[1].a-b.p[2].a;
}
bool cmp2(node a,node b){
	if(a.p[2].a-a.p[3].a==b.p[2].a-b.p[3].a){
		return a.p[2].a>b.p[2].a;
	}
	return a.p[2].a-a.p[3].a>b.p[2].a-b.p[3].a;
}
bool cmp3(node a,node b){
	return a.p[3].a>b.p[3].a;
}
int cl[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&peo[i].p[j].a);
				peo[i].p[j].id=j;
			}
			peo[i].b=0;
			sort(peo[i].p+1,peo[i].p+4,cmp);
		}
		sort(peo+1,peo+n+1,cmp1);
		cl[1]=0,cl[2]=0,cl[3]=0;
		int maxx=n/2;
		int k=1;//按照第1志愿给 
		ll ans=0;
		for(int i=1;i<=n;i++){
			int id=peo[i].p[k].id;
			if(cl[id]+1<=maxx){
				cl[id]++;
				ans+=peo[i].p[k].a;
				peo[i].b=1;
			}
		}
		k=2;
		sort(peo+1,peo+n+1,cmp2);
		for(int i=1;i<=n;i++){
			int id=peo[i].p[k].id;
			if(!peo[i].b && cl[id]+1<=maxx){
				cl[id]++;
				ans+=peo[i].p[k].a;
				peo[i].b=1;
			}
		}
		k=3;
		sort(peo+1,peo+n+1,cmp3);
		for(int i=1;i<=n;i++){
			if(!peo[i].b && cl[peo[i].p[k].id]+1<=maxx){
				cl[peo[i].p[k].id]++;
				ans+=peo[i].p[k].a;
				peo[i].b=1;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
5
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
10
5491 4476 6362
9805 9130 15480
9090 9901 10480
6326 6516 1985
9119 2924 6420
9826 12689 7592
7293 16544 12901
11905 18183 18712
9015 3463 13025
1792 2433 17042
10
3004 4255 17336
11894 5756 17092
8150 14715 10991
5149 16652 16780
11524 11996 5433
7690 10472 19935
1184 6516 9246
3231 5570 10010
8426 16992 4654
18955 13977 16657
10
6839 5455 15586
11767 12919 2643
13775 8904 19938
13717 11997 15170
13707 2404 17497
3471 2462 8073
18467 14346 18663
13582 4839 15785
11875 7476 12308
8568 3134 18522
10
14230 3941 18854
12173 19429 15426
10974 4717 15290
4732 6608 4961
13198 13925 2137
10688 3092 16965
5356 19920 1471
11299 10796 13511
17932 12143 16407
5611 8100 16107

*/
