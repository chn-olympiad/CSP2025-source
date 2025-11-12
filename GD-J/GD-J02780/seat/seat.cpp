#include<bits/stdc++.h>
using namespace std;

int a[105],b[12][12];
int main(){//时间复杂度：n*m+100 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s;
	scanf("%d %d",&n,&m);
	scanf("%d",&s);
	a[s]++;
	for(int i=1;i<n*m;i++){//桶 n*m
	    int d=0;
		scanf("%d",&d);
		a[d]++;
	}
	int r=0,c=0,q=0;
	for(int i=101;i>=0;i--){//100
		if(a[i]!=0){
			b[r][c]=i;
			if(i==s){
				printf("%d %d",c+1,r+1);
				break;
			}
			if(c%2==0){//遍历走向 
				if(r==n-1){
					c++;
					r--;
				}
				r++;
			} 
			else{ 
				if(r==0){
					c++;
					r++;
				}
				r--;
			}
		}
	}
	return 0;
}
