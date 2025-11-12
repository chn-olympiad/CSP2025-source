#include<bits/stdc++.h> 
using namespace std;
const int N=120;
int sc[N],tar;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&sc[i]);
	}
	tar=sc[1];
	sort(sc+1,sc+1+n*m,cmp);
	int rak;
	for(int i=1;i<=n*m;i++){
		if(sc[i]==tar) rak=i;
	}
	//printf("%d\n",rak);
	int x=(rak%m==0?m:rak%m);
	printf("%d %d\n",(((rak)%m!=0)?rak/m+1:rak/m),
	(((rak%m!=0)?rak/m+1:rak/m)%2==1)?x:m-x+1);
	return 0;
}
/*
2 2
99 100 97 98
2 2
98 99 100 97
*/

