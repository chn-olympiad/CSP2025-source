#include <cstdio>
using namespace std;
int a[100000],b[10000],n,m,x=0;
int seat(){
	for(int j=0;j<n*m;j++){
		for(int i=0;i<n*m;i++){
			if(a[j]>a[i]){
				b[0]=a[j];
			}
		}
		}
	for(int j=0;j<n*m;j++){
		for(int i=0;i<n*m;i++){
			if(j>0){
				if(a[j]>=a[i]&&a[j]<b[j-1]){
					b[j]=a[j];
				}
			}
	}if(a[0]==b[0]){
					return 1 ;
					return 1;
			}
		}for(int i=0;i<n*m;i++){
		if(a[0]==b[i]){
			break;
		}else{
			x++;
		}
	}
	if(x%(2*n)==0){
		return x/n ;
		return 1;
	}else{
		if(x%(2*n)<=n){
			return x/n+1 ;
			return x%(2*n);
		}else{
			return x/n+2 ;
			return (2*n+1)-x%(2*n);
		}
	}
	
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n*m;i++){
		scanf("%d",a[i]);
	}
	printf("%d%d",seat());
	return 0;
} 