#include<bits/stdc++.h>
using namespace std;
char letterlist[]="abcdefghijklmnopqrstuvwxyz";
int n,m,a[10000],sa;
bool cmp(int ax,int ay){
	return (ax>ay);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	sa=a[1];
	sort(a+1,a+n*m+1,cmp);
	int i=1,j=1,color=0;
	while(color<n*m){
		color++; 
		if (a[(i-1)*m+j]==sa){
			printf("%d %d",i,j);
			break;
		}
		if (j%2==1){
			if (i==n) j++;
			else i++;
		}else{
			if (i==1) j++;
			else i--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*ofc, n<=10 m<=10 let me laugh.
it's "orange problem".
*/
