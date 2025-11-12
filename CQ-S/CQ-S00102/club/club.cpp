#include<bits/stdc++.h>
using namespace std;
int t,n,nn,kum[100009][3],km[100009];
long long num; 
struct node{
	int num,id;
}uid[209][209][209];
long long dfs(long long numx,int id,int mid,int id1,int id2,int id3){
	long long numm=0;
	if(id==mid){
		return numx;
	}
	if(id1<nn){
		numm=max(numm,dfs(numx+kum[id][1],id+1,mid,id1+1,id2,id3));
	}
	if(id2<nn){
		numm=max(numm,dfs(numx+kum[id][2],id+1,mid,id1,id2+1,id3));
	}
	if(id3<nn){
		numm=max(numm,dfs(numx+kum[id][3],id+1,mid,id1,id2,id3+1));
	}
	return numm;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int h=1;h<=t;h++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&kum[i][1],&kum[i][2],&kum[i][3]);
		}
		nn=n/2;
		num=dfs(0,1,n+1,0,0,0);
		printf("%lld\n",num);
	}
	return 0;
} 
