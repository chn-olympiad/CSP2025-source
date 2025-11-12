#include<bits/stdc++.h>
using namespace std;
int m,n,a[10000],p=1,s1,s2;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m*n;i++){
	scanf("%d",&a[i]);
	if(a[i]<a[1])p++;
	}
	int o=p%8;
	s1=(p+1)/4;
	if(o<5){
	s2=o;
		}
		else{
			s2=4-(o-1)%4;
		}
		printf("%d%d",s1,s2);
	return 0;
	}
