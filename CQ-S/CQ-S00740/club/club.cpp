//the code is from chenjh
#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,m;
struct STU{
	int a[3],p[3];
	void init(){
		for(int j=0;j<3;j++) scanf("%d",&a[j]),p[j]=j;
		sort(p,p+3,[&](const int x,const int y){return a[x]>a[y];});
	}
	int operator [](const int x)const{return a[p[x]];}
}t[MAXN];
int q[MAXN];
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) t[i].init();
	int c[3]={0,0,0},ans=0;
	for(int i=1;i<=n;i++) ++c[t[i].p[0]],ans+=t[i][0],q[i]=i;
	int w=max_element(c,c+3)-c;
	if(c[w]<=(n>>1)){printf("%d\n",ans);return;}
	m=0;
	for(int i=1;i<=n;i++)if(t[i].p[0]==w) q[++m]=i;
	sort(q+1,q+m+1,[](const int x,const int y){return t[x][1]-t[x][0]>t[y][1]-t[y][0];});
	for(int i=c[w]-(n>>1);i>0;--i) ans+=t[q[i]][1]-t[q[i]][0];
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--) solve();
	return 0;
}
/*


Change:



Idea:

直接贪心应该就是对的？

感觉不太对。 

是不是先将其分为两组。 

然后在两组中再找一部分换为第三组。

难道是反悔贪心吗。

优先选多的，多了再考虑微调。

因为最多只会有一个组不满足限制。

多的往少的调整不会造成问题，调到最多的组少于 n/2 即可。 


Command:

g++ club.cpp -o club -O2 -std=c++14 -Wall -Wextra -Wshadow -static
g++ club.cpp -o club -O2 -std=c++14 -Wall -Wextra -Wshadow -fsanitize=address,undefined,signed-integer-overflow -g

copy .\data\club\club1.in club.in /Y
copy .\data\club\club1.ans club.ans /Y
.\club
fc club.out club.ans

copy .\data\club\club2.in club.in /Y
copy .\data\club\club2.ans club.ans /Y
.\club
fc club.out club.ans

copy .\data\club\club3.in club.in /Y
copy .\data\club\club3.ans club.ans /Y
.\club
fc club.out club.ans

copy .\data\club\club4.in club.in /Y
copy .\data\club\club4.ans club.ans /Y
.\club
fc club.out club.ans

copy .\data\club\club5.in club.in /Y
copy .\data\club\club5.ans club.ans /Y
.\club
fc club.out club.ans

cp ../data/club/club1.in club.in
cp ../data/club/club1.ans club.ans
time ./club
diff club.out club.ans -BZ

cp ../data/club/club2.in club.in
cp ../data/club/club2.ans club.ans
time ./club
diff club.out club.ans -BZ

cp ../data/club/club3.in club.in
cp ../data/club/club3.ans club.ans
time ./club
diff club.out club.ans -BZ

cp ../data/club/club4.in club.in
cp ../data/club/club4.ans club.ans
time ./club
diff club.out club.ans -BZ

cp ../data/club/club5.in club.in
cp ../data/club/club5.ans club.ans
time ./club
diff club.out club.ans -BZ


*/

