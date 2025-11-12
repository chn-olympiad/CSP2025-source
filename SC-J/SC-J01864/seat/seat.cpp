#include<bits/stdc++.h>
using namespace std;
int c[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int p=n*m;
	for(int i=1;i<=p;i++) scanf("%d",&c[i]);
	int r=c[1],l,h;
	sort(c+1,c+p+1,cmp);
	for(int i=1;i<=p;i++)
		if(c[i]==r){
			l=(i-1)/n+1;
			if(l%2!=0) h=(i-1)%n+1;
			else h=n-(i-1)%n;
			break;
		}
	printf("%d %d\n",l,h);
	return 0;
}