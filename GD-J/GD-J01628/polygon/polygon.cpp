#include<bits/stdc++.h>
using namespace std;
int n,a[5005],m=998244353,ans;

void b(int x,int y,int z){
	if(x>n) return ;
	int e=0;
	for(int i=z;i<=n;i++){
		y+=a[i];
		if(x>=3){
			if(y>(a[i]*2)){
				e++;
			}
		}
		b(x+1,y,i+1);
		y-=a[i];
	}
	ans=(ans+e)%m;
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	b(1,0,1);
	printf("%d",ans);
	return 0;
}
