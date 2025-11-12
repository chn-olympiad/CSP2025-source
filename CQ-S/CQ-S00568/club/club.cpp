#include<bits/stdc++.h>
using namespace std;
int t,n,maxn,N;
struct node{
	int a,b,c;
}f[100001];
void serch(int nnow,int sa,int sb,int sc,int sum){
	if(sum>maxn)maxn=sum;
	for(int i=nnow;i<=n;i++){
		if(sa<N)serch(i+1,sa+1,sb,sc,sum+f[i].a);
		if(sb<N)serch(i+1,sa,sb+1,sc,sum+f[i].b);
		if(sc<N)serch(i+1,sa,sb,sc+1,sum+f[i].c);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		cin>>n;
		maxn=0;
		N=n/2;
		for(int i=1;i<=n;i++)scanf("%d%d%d",&f[i].a,&f[i].b,&f[i].c);
		serch(1,0,0,0,0);
		printf("%d\n",maxn);
	}
	return 0;
}
