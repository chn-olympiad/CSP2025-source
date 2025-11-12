#include<bits/stdc++.h>
using namespace std;
int score[101],n,m,tar,pos=0,ans1,ans2;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n*m;++i){
		int ls;
		scanf("%d",&ls);
		if(i==0)tar=ls;
		++score[ls];
	}
	for(int i=100;i>=tar;--i)pos+=score[i];
	int pai=pos/(2*n);
	int lie=pos%(2*n);
	int l2=lie/n;
	int l3=lie%n;
	if(l2){
		l3=n-l3+1;
	}
	ans1=2*pai+l2+1;
	ans2=l3;
	printf("%d %d",ans1,ans2);
	return 0;
}