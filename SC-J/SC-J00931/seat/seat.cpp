#include<bits/stdc++.h>
using namespace std;
int n,m,R,Temp;
int a[121],b[11][11];
int number=1;
int hp(int a,int b){
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	Temp=n*m;
	for(int i=1;i<=Temp;i++) scanf("%d",&a[i]);
	R=a[1];
	sort(a+1,a+Temp+1,hp);
	if(n==1&&m==1){
		printf("%d %d",1,1);
		return 0;
	}
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				b[j][i]=a[number];
				number++;
			}
		}
		if(i%2==0){
			for(int j=n;j>=1;j--){
				b[j][i]=a[number];
				number++;
			}
		} 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==R){
				printf("%d %d",j,i);
				return 0;
			}
		}
	}
	return 0;
}