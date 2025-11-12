#include <bits/stdc++.h>
using namespace std;
int n;
struct Andy{
	int a,b,c;
}x[100010];
int ans;
void dfs(int aa,int bb,int cc,int sum){
	if (aa+bb+cc==n){
		ans=max(ans,sum);
		return ;
	}
	if (aa!=n/2){
		dfs(aa+1,bb,cc,sum+x[aa+bb+cc+1].a);
	}
	if (bb!=n/2){
		dfs(aa,bb+1,cc,sum+x[aa+bb+cc+1].b);
	}
	if (cc!=n/2){
		dfs(aa,bb,cc+1,sum+x[aa+bb+cc+1].c);
	}
}
bool cmp1(Andy a,Andy b){
	if (a.a==b.a){
		if (a.b==b.b){
			return a.c>b.c;
		}
		return a.b>b.b;
	}
	return a.a>b.a;
}
void solvea(){
	sort(x+1,x+n+1,cmp1);
	for (int i=1;i<=n/2;i++){
		ans+=x[i].a;
	}
}
bool cmp2(Andy a,Andy b){
	return max(a.a,max(a.b,a.c))>max(b.a,max(b.b,b.c));
}
void solveo(){
	int aa=0,bb=0,cc=0,sum=0;
	for (int i=1;i<=n;i++){
		if (x[i].a==max(x[i].a,max(x[i].b,x[i].c))&&aa!=n/2){
			aa++;
			sum+=x[i].a;
		}
		else if (x[i].b==max(x[i].a,max(x[i].b,x[i].c))||aa==n/2){
			bb++;
			sum+=x[i].b;
		}
		else{
			cc++;
			sum+=x[i].c;
		}
	}
	ans=max(ans,sum);
	aa=0,bb=0,cc=0,sum=0;
	for (int i=1;i<=n;i++){
		if (x[i].a==max(x[i].a,max(x[i].b,x[i].c))&&aa!=n/2){
			aa++;
			sum+=x[i].a;
		}
		else if (x[i].c==max(x[i].a,max(x[i].b,x[i].c))||aa==n/2){
			cc++;
			sum+=x[i].c;
		}
		else{
			bb++;
			sum+=x[i].b;
		}
	}
	ans=max(ans,sum);
	aa=0,bb=0,cc=0,sum=0;
	for (int i=1;i<=n;i++){
		if (x[i].b==max(x[i].a,max(x[i].b,x[i].c))&&aa!=n/2){
			bb++;
			sum+=x[i].b;
		}
		else if (x[i].a==max(x[i].a,max(x[i].b,x[i].c))||bb==n/2){
			aa++;
			sum+=x[i].a;
		}
		else{
			cc++;
			sum+=x[i].c;
		}
	}
	ans=max(ans,sum);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while (t--){
		ans=0;
		scanf("%d",&n);
		int A=1;
		for (int i=1;i<=n;i++){
			scanf("%d%d%d",&x[i].a,&x[i].b,&x[i].c);
			if (x[i].b){
				A=0;
			}
		}
		if (n<=10){
			dfs(0,0,0,0);
		}
		else if (A){
			solvea();
		}
		else{
			solveo();
		}
		printf("%d\n",ans);
	}
	return 0;
}
