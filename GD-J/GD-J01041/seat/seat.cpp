#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,a[N],bb,d;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	bb=a[1];
//	printf("bb%d ",bb);
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==bb){
			d=i;
			break;
		}
	}
//	printf("d%d ",d);
	for(int l=1;l<=m;l++){
		if(l%2==1){
			for(int h=1;h<=n;h++){
				d--;
//				printf("%d %d %d\n",d,l,h);
				if(!d){
					printf("%d %d",l,h);
					return 0;
				}
			}
		}
		else{
			for(int h=n;h>=1;h--){
				d--;
				if(!d){
					printf("%d %d",l,h);
					return 0;
				}
			}
		}
	}
}
