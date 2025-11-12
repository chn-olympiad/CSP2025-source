#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e5+5;
int T,n;
int a[maxn][5];
struct A12{
	int a1,a2;
};
bool cmp(A12 x,A12 y){
	return abs(x.a1-x.a2)>abs(y.a1-y.a2);//按差排序
}
void solveAB(){//
	int ans=0,cnt1=0,cnt2=0;
	A12 c[maxn];
	for(int i=1;i<=n;i++){
		c[i].a1=a[i][1];
		c[i].a2=a[i][2];
	}
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(cnt1<n/2 && cnt2<n/2){
			if(c[i].a1>c[i].a2)cnt1++,ans+=c[i].a1;
			//相等不必考虑,说明接下来的都是1,2都可选的，随便分 
			else cnt2++,ans+=c[i].a2;
		}
		else{
			if(cnt1<n/2)cnt1++,ans+=c[i].a1;
			else cnt2++,ans+=c[i].a2;
		}
	}
	printf("%d\n",ans);
}
int dfs(int x,int cnt1,int cnt2,int cnt3){//暴力+剪枝 n=25 时 <O(5e6)
	if(cnt1>n/2||cnt2>n/2||cnt3>n/2)return -1e9;
	if(x>n)return 0;
	return max(dfs(x+1,cnt1+1,cnt2,cnt3)+a[x][1],
		   max(dfs(x+1,cnt1,cnt2+1,cnt3)+a[x][2],
			   dfs(x+1,cnt1,cnt2,cnt3+1)+a[x][3]));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		bool AB=true;//性质 A 和 B 
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][3]!=0)AB=0;
		}
		if(AB)solveAB();
		else if(n<=30)printf("%d\n",dfs(1,0,0,0));
	}
	return 0;
}
