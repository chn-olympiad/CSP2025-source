//seat.cpp
#include<stdio.h>
#include<algorithm>

int n,m,a[(int)150],rr,l=1,r=1;
bool zf=0;//0:z,1:f

void solve(){
	for(int i=n*m;i>=1;i--){
		//printf("ddd,i%d,a[i]%d,r%d,l%d,zf%d\n",i,a[i],r,l,zf);
		if(rr==a[i]){
			printf("%d %d",r,l);
			return ;
		}
		
		if(zf==0){
			l++;
			if(l>n){
				zf=1;r++;l-=1;
				continue;
			}
		}else if(zf==1){
			l--;
			if(l<1){
				zf=0;r++;l+=1;
				continue;
			}
		}
	}
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(i==1){
			rr=a[i];
		}
	}
	std::sort(a+1,a+n*m+1);
	//printf("%d",a[0]);
	//system("pause");
	solve();
	return 0;
}
