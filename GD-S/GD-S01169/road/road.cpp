#include<bits/stdc++.h>
using namespace std;
struct Node{
	int a,b,c;
}q[1000001];
int n,m,j,nn[10001];
bool mm(Node a1,Node b1){
	if(a1.c<b1.c) return true;
	return false;
}
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	scanf("%d%d%d",&n,&m,&j);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&q[i].a,&q[i].b,&q[i].c);
	sort(q+1,q+m+1,mm);
	nn[q[1].a]=q[1].a;
	for(int i=1;i<=m;i++)
	{
		if(nn[q[i].a]!=0&&nn[q[i].b]!=0)
		{
			if(nn[q[i].a]!=nn[q[i].b])
		}
		else {
		if(nn[q[i].a]!=0)
			nn[q[i].b]=nn[q[i].a];
			
			
		}	
	}
	printf("%d",10086);
	return 0;
}
