#include<cstdio>
#include<algorithm>

#define ll long long
//#define int long long
short list[200]={};
using namespace std;

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n*m;i++){
		scanf("%d",list+i);
	}
	a=list[0];
//	bool
//      operator()(const _Tp& __x, const _Tp& __y) const
//      { return __x > __y; }
	std::sort(list,list+n*m,[](const short& x,const short& y){return x > y;});;
//	for(int i=0;i<n*m;i++){
//		printf("%d ",list[i]);
//	}
	int at=find(list,list+n*m,a)-list;
	if(at==n*m)printf("[Error]");
	printf("%d %d",at/n/2*2+(at%(n*2)>=n)+1,((at%(n*2)>=n)?(n-at%n):(at%n+1)));
} 
