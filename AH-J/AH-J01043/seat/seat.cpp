#include<cstdio>
#include<algorithm>
int n,m,a[105],t[2]={1,-1};
int r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;++i){
		scanf("%d",&a[i]);
	}
	r=a[1];
	int ming;
	std::sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		// printf("%d\n",a[i]);
		if(a[i]==r){
			ming=n*m-i+1;break;
		}
	}
	int x=1,y=1;

	for(int f=0,i=1;i<ming;++i){
		if(f==0&&x==n){
			++y;
			f=1;
		}else if(f==1&&x==1){
			++y;
			f=0;
		}else{
			x+=t[f];
		}
	}
	printf("%d %d",y,x);
	return 0;
}