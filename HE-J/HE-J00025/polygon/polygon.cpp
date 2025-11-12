#include<bits/stdc++.h>
using namespace std;
int num=1;

void dfs(int a,int b,int c){
	if(a+b+c>2*max(a,b,c)){
		num++;
	}
}
void dfs1(int e,int f,int g,int d){
	int maxn1=max(e,f);
	int maxn2=max(g,d);
	if(e+f+g+d>2*max(maxn1,maxn2)){
		num++;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int a[n];
	scanf("%d",&n);
	for(int i=0;i<=n-1;i++){
		scanf("%d",&a[i]);	
	} 
	for(int i=0;i<=n-1;i++){
		int l1=i,l2=i+1,l3=i+2;
		dfs(a[l1],a[l2],a[l3]);
		l3++;
		dfs(a[l1],a[l2],a[l3]);
		l3--;
		dfs(a[l1],a[l2],a[l3]);
		l2++;
		dfs(a[l1],a[l2],a[l3]);
		l2--;
		dfs(a[l1],a[l2],a[l3]);
		l1++;
		dfs(a[l1],a[l2],a[l3]);
		l1--;
	}
	for(int i=0;i<=n-1;i++){
		int l1=i,l2=i+1,l3=i+2,l4=i+3;
		dfs1(a[l1],a[l2],a[l3],a[l4]);
		l4++;
		dfs1(a[l1],a[l2],a[l3],a[l4]);
		l4--;
		dfs1(a[l1],a[l2],a[l3],a[l4]);
		l3++;
		dfs1(a[l1],a[l2],a[l3],a[l4]);
		l3--;
		dfs1(a[l1],a[l2],a[l3],a[l4]);
		l2++;
		dfs1(a[l1],a[l2],a[l3],a[l4]);
		l2--;
		dfs1(a[l1],a[l2],a[l3],a[l4]);
		l1++;
		dfs1(a[l1],a[l2],a[l3],a[l4]);
		l1--;
	}
	printf("%d",num);
	return 0;
}
