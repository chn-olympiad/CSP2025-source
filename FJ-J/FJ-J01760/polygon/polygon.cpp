#include<bits/stdc++.h>
#define N 5050
//#define int long long
/*	ans是不是有问题啊，为啥没 % 244 
	难道是我理解错了？ 
	“由于答案可能较大，你只需要求出答案对998, 244, 353 取模后的结果。”
	应该是这个意思吧
	希望是
	*/
using namespace std;
class node{
	public:
		int sum,maxn;
		int x;
};
int a[N],n;
int bfs(){
	int cnt=0;
	queue<node>q;
	q.push({0,0,0});
	while(!q.empty()){
		node nur=q.front();
		q.pop();
		if(nur.maxn*2<nur.sum)cnt=cnt+1;
		if(nur.x>n)continue;
		else{
			for(int i=nur.x+1;i<=n;i++){
				node v;
				v.x=i,v.maxn=max(nur.maxn,a[i]),v.sum=nur.sum+a[i];
				q.push(v);
			}
		}
	}
	return cnt;
}
/*暴力bfs应该能有40 50分吧*/
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	printf("%d",(bfs())%244);
	return 0;
}
