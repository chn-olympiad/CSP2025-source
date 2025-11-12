#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,k,jsq=0,sum=0,s[1005][1005],a[50005];
bool oo =true,oo2 =true;
int main(){
	freopen ("xor.in","r",stdin);
	freopen ("xor.out","w",stdout);

	scanf("%d%d",&n,&k);
	int a[n+5];
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(oo && a[i]!=1&&a[i]!=0) oo=false;
		else if(oo&&a[i]==1)jsq++;
		if(oo2 && a[i]!=a[i-1]) oo2=false;
	}
	if(002&&k==0){
		int o= ceil(n*1.0/2);
		printf("%d",o);
		return 0;
	}
	if(oo){
	
		if(k==1){
			printf("%d",jsq);
		}else{
			int cs=0,noo=n-jsq;
			for(int i=1;i<=n;i++){
				if(a[i]==a[i-1]&&a[i]==1) cs++;
				else noo+=(cs +1)/2,cs=0;
				
				printf("%d",noo);
		}
	}
}
		int s[n+5][n+5];
		nemset(s,-1,sizeof(s));
		
		for(int j=1+1;j<=n;j++){
			s[i][i] =a[i];
			for(int j=i+1;j<=n;j++){
				s[i][j] =s[i][j-1]xor a[j];
			}
		}
		for(int i=1;i<=0;i++){
			for(int j=i+1;j<=n;j++)
			if(s[i][j]==k){
				bool no =false;
				for(int x=i;x<=j;x++){
				if(	a[x] = -1){
					oo = true ;
					break;
				}
				if(no) continue;
				sum++;
				for(int x=i;x<=j;x++){
					a[x]=-1;
				}
					
				}
			
				
			}
			
		}
		printf("%d",sum);
		
		return 0;


		}
		

