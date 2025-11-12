#include<bits/stdc++.h>
#define N 100005
using namespace std;
int t;
int n;
int m[N][3];
int num[3];
int ans;
void baoli(int l,int sum,int a,int b,int c){
	if(l==n){
		ans=max(ans,sum);
		return ;
	}
	if(a<n/2) baoli(l+1,sum+m[l][0],a+1,b,c);
	if(b<n/2) baoli(l+1,sum+m[l][1],a,b+1,c);
	if(c<n/2) baoli(l+1,sum+m[l][2],a,b,c+1);
	return ;
}
void ma(){
	ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<3;j++)
			scanf("%d",&m[i][j]);
	baoli(0,0,0,0,0);
	printf("%d\n",ans);
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=0;i<t;i++) ma();
	return 0;
}
