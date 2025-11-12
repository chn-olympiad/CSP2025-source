#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],rsc,se,r,c=1;
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&rsc);
	for(int i=1;i<=n*m-1;i++){scanf("%d",&a[i]);}
	sort(a+1,a+n*m,cmp);
	for(int i=1;i<=n*m-1;i++){
		if(rsc>a[i]){se=i;break;}
	}
	while(c*n<se)c++;
	if(c%2){
		r=se-(c-1)*n;
	}else{
		r=n-(se-(c-1)*n)+1;
	}
	printf("%d %d",c,r);
	return 0;
}
