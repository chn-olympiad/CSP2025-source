#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a;
	scanf("%d%d%d",&n,&m,&a);
	int kk=n*m,b,s=0;
	for(int i=2;i<=kk;i++){
		scanf("%d",&b);
		if(b>a)s++;
	}
	int l=1,r=1,k=1;
	while(s){
		l+=k;
		if(l==n+1){
			k=-1;
			l=n;
			r++;
		}
		if(l==0){
			k=1;
			l=1;
			r++;
		}
		s--;
	}
	printf("%d %d",r,l);
	return 0;
}
