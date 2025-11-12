#include <iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,cj;
int a[110];
bool cmp(int x,int y){
	return x>y;
}
int main (){
	freopen("seat.in","r",stdin)
	freopen("seat.out","w",stdout)
	scanf("%d %d",&n,&m);
		for(int i=0;i<=n*m;i++){
			scanf("%d",&a[i]);
		
		cj=a[i];
	}
	
	sort(a+1,a+1+n*m,cmp);
	if(a[1]==cj){
		printf("%d %d",1,1);
	}
	int l=1,h=1;
	for(int i=2;i<=m*n;i++){
	
		if(i%2==1){
			if(h!=1){
			h++;
			}
			else{
			l++;
	   	 }	
		}
	
		else{
			if(h!=1){
				h--;
			}else{
				l++;
			}
		
				
			}
		
		if(a[i]==cj){
				printf(" %d %d",l,h);	
		}
				
	}
	
			
				fclose(stdin);
				fclose(stdout);
				return 0;	
}


