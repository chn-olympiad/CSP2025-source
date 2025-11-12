#include<iostream>
#include<string.h>
using namespace std;
int n,m,j;
int stu[150][150],t[150];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	j=n*m+1;
		int g;
		scanf("%d",&g);
		t[g]++;
	for(int i=2;i<=n*m;i++){
		int goa;
		scanf("%d",&goa);
		t[goa]++;
	}
	for(int i=g;i>=0;i--){
		if(t[i]==1){
			j--;
			}
		}

		printf("%d ",(j-1)/n+1);
if(((j-1)/n+1)%2==1){
printf("%d",(j-1)%n+1);

}else{
	printf("%d",n-(j-1)%n);
	}

	return 0;
}

