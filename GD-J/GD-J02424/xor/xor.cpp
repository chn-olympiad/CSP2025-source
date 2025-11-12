//xor.cpp
#include<stdio.h>
#include<climits>
int n,k,ans,a[(int)1e5*5+5],sum;
//const int mx=2147483647;
void solve(int l,int r){
	sum=0;
	if(l==r){
		sum=a[l];
		//printf("done,%d\n",sum);
		if(sum==k){
			ans++;
			a[l]=-1;
			
			//break;
		}
		return ;
	}
	for(int i=l;i<=r;i++){
		if(a[i]==-1){
			sum=-1;
			break;
		}
		sum=sum xor a[i];
	}
	if(sum==k){
		for(int i=l;i<=r;i++){
			a[i]=-1;
		}
		ans++;
		//break;
	}
	//printf("ddd,ans%d,sum%d,l%d,r%d\n",ans,sum,l,r);
	//for(int i=1;i<=n;i++){
	//	printf("%d,",a[i]);
	//}
	//puts("");
	return ;
}

int main(){
	//printf("%d",1 xor 2);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	//printf("%d",INT_MAX);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			solve(i,j);
		}
	}
	printf("%d",ans);
	return 0;
}
