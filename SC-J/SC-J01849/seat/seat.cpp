#include<bits/stdc++.h>
using namespace std;

#define Fre(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout);

int n,m;
int a[200];

int main(){
	Fre("seat");
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;++i) scanf("%d",a+i);
	int R=a[1];
	sort(a+1,a+n*m+1,[](int a,int b){return a>b;});
	for(int i=1;i<=n*m;++i)
		if(a[i]==R){
			int c=(i-1)/n+1,r=(i-1)%n+1;
			printf("%d %d\n",c,(c&1?r:n-r+1));
			break;
		}
	
	return 0;
}