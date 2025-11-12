#include<bits/stdc++.h>

using namespace std;

int n,m;
int a[101];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	
	int x=a[1];
	
	sort(a+1,a+n*m+1,cmp);
	
	int x1=1,y1=0;
	
	for(int i=1;i<=n*m;i++){
		if(x1%2==1){
			y1++;
			if(y1>m){
				y1=m;
				x1++;
			}
		}
		
		else{
			if(x1%2==0){
				y1--;
				if(y1<1){
					y1=1;
					x1++;
				}
			}
		}
		
		if(a[i]==x){
			printf("%d %d",x1,y1);
			return 0;
		}
	}
}
