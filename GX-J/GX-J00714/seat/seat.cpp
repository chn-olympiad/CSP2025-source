#include<bits/stdc++.h>
using namespace std;
int a[1000000];
bool Fun(int a,int b){
	return a > b;
}
int main(void){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	int c = n * m;
	for(int i = 1;i <= c;i++){
		scanf("%d",&a[i]);
	}
	int xa = a[1],index;
	sort(a +1 , a+ c + 1,Fun);
	for(int i = 1;i <= c;i++){
		if(a[i] == xa){
			index = i;
		}
	}
	if(index % n != 0){
		int Index = index % n;
		int num = index / n + 1;
		if(num % 2 == 0){
			printf("%d %d",num,n - Index + 1);
		}else{
			printf("%d %d",num,Index);
		}
	}else if(index % n == 0){
		int num = index / n;
		if(num % 2 == 0){
			printf("%d 1",num);
		}else{
			printf("%d %d",num,n);
		}
		
	}
	
	
	return 0;
}
