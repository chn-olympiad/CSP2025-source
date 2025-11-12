#include<bits/stdc++.h>
using namespace std;
const int N=21;
int n,m,cp,a,num=1,l,h;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&cp);
	for(int i=2;i<=n*m;++i){
		scanf("%d",&a);
		if(a>cp) ++num;
	}
	l=num/n+(bool)(num%n);
	h=(l&1)?(num-(l-1)*n):(n-(num-(l-1)*n)+1);
	printf("%d %d",l,h);
	return 0;
}
