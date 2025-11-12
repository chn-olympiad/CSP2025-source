#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
return a>b;
}
int a[10009];
int n,m,d=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m); 
	for(int i=1;i<=n*m;i++){
	    scanf("%d",&a[i]); ;
	    if(i==1){
	    d=a[i];
	    }
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
	    if(a[i]==d){
	        if(i<=m){
	            printf("1  %d",m);
	            return 0;
	        }
	        else{
	            for(int t=1;t<=n;t++){
	                if(i<=t*m){
	                    if(t%2==0){
                    	printf("%d  %d",t,m-(i-(t-1)*m)+1);
	                    return 0;
	                    }
	                    else{
	                    printf("%d  %d",t,i-(t-1)*m)+1;
	                    }
	                }
	            }
	        }
	    }
	}
	return 0;
}
