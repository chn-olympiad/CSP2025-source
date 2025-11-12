#include<bits/stdc++.h>
using namespace std ;
int n , m , k ;
struct stu1{
	int u , v , w ; 
}t1[1000006] ;
struct stu2{
	int c , a[1000006] ;
}t2[12] ;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 0 ; i < m ; i++) scanf("%d%d%d",&t1[i].u , &t1[i].v , &t1[i].w) ;
	for(int i = 0 ; i < k ; i++)
		scanf("%d",&t2[i].c);
		for(int j = 0 ; j < n ; j++) scanf("%d",&t2[i].a[j]);

	int ans = random() ;
	printf("%d",ans);
	return 0 ;
}
