//GZ-S00480 安顺市第一高级中学 陈详镒菘 

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 600;

bool vis[MAXN];
long long n,m,a[MAXN];
long long cnt = 0;
char s[MAXN];

void dfs(int num,int gu){
	
	if(num == n+1){
		
		if(gu <= n - m)cnt++;
		
		return;
		
	}
	
	if(m == n && gu == 1)return;
	
	for(int i = 1;i <= n;i++){
		
		//printf("plan to choose %d in %d\n",i,num);
		
		if(vis[i])continue;
		
		vis[i] = 1;
		
		int is_gu = 0;
		
		if(gu >= a[i])is_gu = 1;
		else if(s[num-1] == '0')is_gu = 1;
		
		//printf("choose %d correct he is %d\n",i,is_gu);
			
			dfs(num+1,gu + is_gu);
			
			vis[i] = 0;
			
	}
	
	return;
	
}

int main () {
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%lld %lld",&n,&m);
	
	getchar();
	
	for(int i = 0;i < n;i++){
		
		scanf("%c",&s[i]);
		
		//printf("%c ",s[i]);
		
	}
	
	for(int i = 1;i <= n;i++){scanf("%lld",&a[i]);}
	
	for(int i = 1;i <= n;i++)vis[i] = 0;
	
	dfs(1,0);
	
	printf("%lld\n",cnt);
	
	return 0;
}
