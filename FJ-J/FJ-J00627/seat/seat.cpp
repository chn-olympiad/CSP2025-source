#include<bits/stdc++.h>
using namespace std;

int m,n;
int mark,temp;
int seats;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//行数是n
	//列数是m
	/*   列/m1   2   3  4 
	  行/n 
	  1      0   7   8  15
	  2      1   6   9  14
	  3      2   5   10 13
	  4      3   4   11 12
	*/ 
	scanf("%d%d%d",&n,&m,&mark);
	for(int i=1;i<n*m;++i){
		scanf("%d",&temp);
		if(temp>mark){
			seats++;
		}
	}
	printf("%d %d",seats/n+1,seats/n%2?n-seats%n:seats%n+1);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
