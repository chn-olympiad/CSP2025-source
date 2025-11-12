#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,shang,yushu,a[105],rk;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	cnt=n*m;
	rk=1;
	for(int i=1;i<=cnt;i++){
		scanf("%d",&a[i]);
		if(a[i]>a[1])rk++;
	}
	shang=rk/n;
	yushu=rk%n;
	if(yushu!=0)shang+=1;
	if(yushu==0){
		yushu=n;
	}
	if(shang%2==1){
		printf("%d %d",shang,yushu);
	}
	else{
		printf("%d %d",shang,n-yushu+1);
	}
	return 0;
}
