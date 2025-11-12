#include<bits/stdc++.h>
using namespace std;

inline int in(){
	int x=0,t=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')t=-t;c=getchar();}
	while('0'<=c&&c<='9')x=x*10+(c^48),c=getchar();
	return x*t;
}
inline void out(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)out(x/10);
	putchar(x%10^48);
}
const int zj=1e5+10;
int t,n;
int num,ans;
int cnt[5];
//int a[zj][5];
struct node{
	int val[4];
	int sum;
}a[zj];
bool cmp(node x,node y){
	return x.sum>y.sum;
}
int ma=0,ma_x,ma_y;
vector<int>v;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=in();
	while(t--){
		n=in();
		ans=0,num=n>>1;
//		memset(a[],0,sizeof(a));
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;++i){
			a[i].sum=0;
			a[i].sum+=a[i].val[1]=in(),a[i].sum+=a[i].val[2]=in(),a[i].sum+=a[i].val[3]=in();
		}
		sort(a+1,a+1+n,cmp);
		for(int i=2;i<=n;++i){
			ma=0,ma_x=0,ma_y=0;
			for(int j=1;j<=3;++j){
				for(int e=1;e<=3;++e){
					if(a[i].val[j]+a[i-1].val[e]>ma&&cnt[j]+1<=num&&cnt[e]+1<=num){
						if(e==j&&cnt[e]+2>num){
							continue;
						}
						ma=a[i].val[j]+a[i-1].val[e];
						ma_x=j,ma_y=e;
					}
				}
			}
			ans+=a[i-1].val[ma_y];
			++cnt[ma_y];
		}
		ma=0;
		for(int i=1;i<=3;++i){
			if(cnt[i]+1<=num){
				ma=max(ma,a[n].val[i]);
			}
		}
		out(ans+ma),putchar('\n');
	}
	return 0;
}
/*
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

18
4
13

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