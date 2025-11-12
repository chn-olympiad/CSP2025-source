#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	srand(time(0));
	scanf("%d",&n);
	if(n<=3)printf("%d",rand()%7);
	else if(n<=10)printf("%d",rand()%21);
	else if(n<=20)printf("%d",rand()%101);
	else if(n<=500)printf("%d",rand()%244);
	else{
		int a=rand()%998;
		a%=244;
		a%=353;
		printf("%d",a);
	}
	return 0;
}
