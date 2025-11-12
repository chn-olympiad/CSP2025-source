/*#include<bits/stdc++.h>
using namespace std;

int q[100010],h = 1,t;
int x1,x2,x3;
int T,n,ans;
struct node{
	int a,b,c;
}a[100010];
bool cmp(node x,node y){
	if(x.a != y.a)return x.a>y.a;
	if(x.b != y.b)return x.b>y.b;
	return x.c>y.c;
}
int main(){
	freopen("club4.in","r",stdin);
	//freopen("club.out","w",stdout);
	
	
	scanf("%d",&T);
	while(T--){
		h = 1,t = 0;
		ans = 0;
		scanf("%d",&n);
		for(int i = 1;i<=n;i++){
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
		}
		sort(a+1,a+n+1,cmp);
		for(int i = 1;i<=n;i++){
			if(x1<n/2){
				x1++;
				ans += a[i].a;
				while(h<=t&&a[q[t]].a>a[i].a)t--;
				q[++t] = i;
			}
			else if(x1 == n/2){
				int x = q[h++];
				ans = max(ans+max(a[i].b,a[i].c),ans+a[i].a-a[x].a+max(a[x].b,a[x].c));
			}
		}
		printf("%d\n",ans);
		
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;

int T,n,ans;
struct node{
	int a,b,c;
}a[100010];
bool cmp(node x,node y){
	return x.a>y.a;
}
void dfs(int now,int x1,int x2,int x3,int cnt){
	
	if(now >n){
		ans = max(ans,cnt);
		return ;
	}
	if(x1<n/2)dfs(now+1,x1+1,x2,x3,cnt+a[now].a);
	if(x2<n/2)dfs(now+1,x1,x2+1,x3,cnt+a[now].b);
	if(x3<n/2)dfs(now+1,x1,x2,x3+1,cnt+a[now].c);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	
	scanf("%d",&T);
	while(T--){
		ans = 0;
		scanf("%d",&n);
		for(int i = 1;i<=n;i++){
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
		}
		if(n<=10){
			dfs(0,0,0,0,0);
			printf("%d\n",ans);
		}else if(a[1].b == 0&&a[1].c == 0&&a[2].b == 0&&a[2].c == 0){
			sort(a+1,a+n+1,cmp);
			for(int i = 1;i<=n/2;i++){
				ans += a[i].a;
			}
			printf("%d\n",ans);
		}
		
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
