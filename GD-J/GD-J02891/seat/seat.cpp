#include<cstdio>
#include<algorithm>
bool cmp(int a,int b){
	if(a>=b)return 1;
	return 0;
}
int n,m,a[105],c,r,x=1,y,st;
bool flag;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	scanf("%d%d",&n,&m);
	int s=n*m;
	scanf("%d",&st);
	for(int i=1;i<s;i++){
		scanf("%d",&a[i]);
	}
	a[0]=0x7ffff;
	std::sort(a,a+s,cmp);
	if(m%2!=0)m++;
	y=2*n+1;
	for(int i=1;i<=m/2;i++){
		if(a[x]>st&&st>a[y]){
			for(int j=x;j<y;j++){
				if(a[j-1]>st&&st>a[j]){
					if(y-j<=n){
						c=2*i;
						if(j%n!=0)r=n-(j%n)+1;
						else r=n-(j%n);
						flag=1;
						break;
					}
					else{
						c=2*i-1;
						if(j%n!=0)r=j%n;
						else r=n;
						flag=1;
						break;
					}
				}
			}
		}
		if(flag)break;
		x=y;
		y=2*n+x;
	}
	printf("%d %d",c,r);
	return 0;
}
