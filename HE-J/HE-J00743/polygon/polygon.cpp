#include<bits/stdc++.h>
using namespace std;
int a,b,max1,m,sum,num[5000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&num[i]);
	}
	for(int i=0;i<(1<<m);i++){
		a=0;
		b=0;
		max1=0;
		for(int j=0;j<m;j++){
			if((i/(1<<j))%2==1){
				b++;
				a+=num[j];
				max1=max(max1,num[j]);
			}
		}
		if(b>=3&&a>max1*2){
			sum++;
		}
	}
	printf("%d",sum);
	return 0;
}
