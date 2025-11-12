#include <iostream>//如果出错，看看有没有变量命名成a,b,c了
#include <algorithm>
#include <cstring>
#define a p[i].x[0]
#define b p[i].x[1]
#define c p[i].x[2]
using namespace std;
int T;
int n,cnt[3];
struct People{
	int x[3];
	int x1,x2;
}p[100010];
bool cmp(const People &x,const People &y){
	return x.x[x.x1]-x.x[x.x2]>y.x[y.x1]-y.x[y.x2];
}
void xyb(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
}
int main(){
	xyb();
	cin>>T;
	while(T--){
		scanf("%d",&n);
		cnt[0]=cnt[1]=cnt[2]=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a,&b,&c);
			if(b>a){
				if(c>b){//c b a
					p[i].x1=2;
					p[i].x2=1;
				}
				else{
					p[i].x1=1;
					if(a>c)p[i].x2=0;//b a c
					else p[i].x2=2;//b c a
				}
			}
			else{
				if(c>a){//c a b
					p[i].x1=2;
					p[i].x2=0;
				}
				else{
					p[i].x1=0;
					if(b>c)p[i].x2=1;//a b c
					else p[i].x2=2;//a c b
				}
			}
		}
		sort(p+1,p+1+n,cmp);
		long long ans=0;
		for(int i=1;i<=n;i++){
			//printf("%d %d %d\n",a,b,c);
			if(cnt[p[i].x1]<n>>1){
				cnt[p[i].x1]++;
				ans+=p[i].x[p[i].x1];
			}
			else{
				cnt[p[i].x2]++;
				ans+=p[i].x[p[i].x2];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
10
      9963 <19722>
     14533 <18961>
     14615 <17976>
      3195 <9953>
      6224 <16178>
<16441>    10926
     13424 <16615>
     15344 <16322>
8375<10557>
<8769>      4394



1910 6224 16178
2038 9963 19722
958 3195 9953
16441 5313 10926
2020 14533 18961
8769 509 4394
3518 14615 17976
6188 13424 16615
8375 10557 5444
2423 15344 16322

*/
