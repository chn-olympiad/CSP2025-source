# include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x,idx;
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			idx=i;
//			printf("%d\n",idx);
			break;
		}
	}
	int k=idx/m,y=idx%m;
	if(!(y%2)){
		k--;
		y+=m;
	}
	if(k%2){
		printf("%d %d",k+1,m+1-y);
	}else{
		printf("%d %d",k+1,y);
	}
	return 0;
}