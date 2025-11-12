#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int t;
int n;
int ans;
int res1;
int sum1[MAXN],sum2[MAXN],sum3[MAXN];
int cnt1,cnt2,cnt3;
	
struct node{
	int x1,x2,x3;
}a[MAXN];

struct Node{
	int f;
	int s;
	int t;
};

bool cmp(node x,node y){
	return x.x1>y.x1;
}

void dfs(int now){
	//cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<endl; 
	//选完了
	if(now==n){
		//cout<<res1<<endl;
		ans=max(ans,res1);
		return;
	}
	//选第一种
	if(cnt1<n/2){
		cnt1++;
		res1+=a[now+1].x1;
		dfs(now+1);
		cnt1--;
		res1-=a[now+1].x1;
	}
	//选第二种
	if(cnt2<n/2){
		cnt2++;
		res1+=a[now+1].x2;
		dfs(now+1);
		cnt2--;
		res1-=a[now+1].x2;	
	}
	//选第三种 
	if(cnt3<n/2){
		cnt3++;
		res1+=a[now+1].x3;
		dfs(now+1);
		cnt3--;
		res1-=a[now+1].x3;
	}
}

void solve1(){
	Node x;
	for(int i=1;i<=n;i++){
	}
}

void work(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].x1,&a[i].x2,&a[i].x3);
		sum1[i]=sum1[i-1]+a[i].x1;
		sum2[i]=sum2[i-1]+a[i].x2;
		sum3[i]=sum3[i-1]+a[i].x3;
	}
	ans=0;
	cnt1=0,cnt2=0,cnt3=0;
	if(n<=10){
		res1=0;
		dfs(0);
		printf("%d\n",ans);
	}else if(sum3[n]==0){
		if(sum2[n]==0){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].x1;
			}
			printf("%d\n",ans);
		}else{
			solve1();
			printf("%d\n",ans);
		}
	}else{
		res1=0;
		dfs(0);
		printf("%d\n",ans);
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		work();
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
*/
