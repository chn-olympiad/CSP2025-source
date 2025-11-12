#include<bits/stdc++.h>
using namespace std;
int const n=1e5;
int num=0;
int a[n+1];
int b[n+1];
int c[n+1];
void fun(){
	int n1=n;
	while(n1){
		int maxna=0,maxnb=0,maxnc=0;
		for(int i=1;i<=n1-1;i++){
			a[i]=0;
			if(a[i]>maxna){
				maxna=a[i];
				a[i]=-1;
				a[i-1]=0;
			}
			b[i]=0;
			if(b[i]>maxnb){
				maxnb=b[i];
				b[i]=-1;
				b[i-1]=0;
			}
			c[i]=0;
			if(c[i]>maxnc){
				maxnc=c[i];
				c[i]=-1; 
				c[i-1]=0;
			}
		}
		num=num+maxna+maxnb+maxnc;
		if(n1-3>=3){
			n1-=3;
			fun();
		}
		else{
			int m=n1-3;
			while(n){
				for(int i=1;i<=m;i++){
					maxna=0,maxnb=0,maxnc=0;
					a[i]=0;
					if(a[i]>maxna){
						maxna=a[i];
						a[i]=-1;
						a[i-1]=0;
					}
					b[i]=0;
					if(b[i]>maxnb){
						maxnb=b[i];
						b[i]=-1;
						b[i-1]=0;
					}
					c[i]=0;
					if(c[i]>maxnc){
						maxnc=c[i];
						c[i]=-1; 
						c[i-1]=0;
					}
					int maxnt=max(maxna,maxnb,maxnc);
					num+=maxnt;
				}
				n1--;
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int f=0,s=0,t=0;
	int k;//k:×éÊý 
	scanf("%d,%d",k,n);
	
	while(k){
		for(int i=1;i<=n;i++){
			scanf("%d,%d,%d",a[i],b[i],c[i]);
		}
		fun();
	}	
	printf("%d",num);
	
	
	return 0;
} 
