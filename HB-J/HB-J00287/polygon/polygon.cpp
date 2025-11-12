#include<bits/stdc++.h>
using namespace std;
int a[5005];
bool v[5005];
int b[5005];
int sum;
int n;
void f(int z,int m){
	if(m>=z){
		int maxn=b[m],num=0;
		for(int i=1;i<=z;i++){
			num+=b[i];
		}
		if(num>maxn*2)sum++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0&&i>=b[i]&&a[i]!=0){
			v[i]=1;
			b[m]=a[i];
			f(z, m+1);
			v[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(n==3){
		int x=max(a[1],a[2]);
		x=max(x,a[3]);
		if(a[1]+a[2]+a[3]>x*2){
			printf("1");
			return 0;
		}
		else{
			printf("0");
			return 0;
		}
	}
	if(n<3){
		printf("0");
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n-1;j++){
				if(a[j]>a[j+1])swap(a[j],a[j+1]);
			}
		}
		for(int i=3;i<=n;i++)f(i,1);
		printf("%d",sum);
	}
	return 0;
}
