#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[110];
int k[2];
int bobboh;
int pai,lei;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	k[1]=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==k[1]){
			bobboh=i;
			break;
		}
	}
	bobboh=abs(bobboh-1-n*m);
	if(bobboh%m==0){
		lei=bobboh/m;
	}
	else{
		lei=bobboh/m+1;
	}
	bobboh=bobboh%m;
	if(lei%2==1){
		pai=bobboh;
	}
	else{
		pai=n-bobboh+1;
	}
	printf("%d %d",lei,pai);
	return 0;
}