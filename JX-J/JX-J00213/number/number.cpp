#include <bits/stdc++.h>
#include <stdio.h>
#include <cstdio>
using namespace std;
int a[100001];
int i=1,x1=0,x2=0,x3=0,x4=0,x5=0,x6=0,x7=0,x8=0,x9=0,x0=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(1){
		if(scanf("\n")) break;
		cin >> a[i];
		i++;
		if(a[i]==1) x1++;
		if(a[i]==2) x2++;
		if(a[i]==3) x3++;
		if(a[i]==4) x4++;
		if(a[i]==5) x5++;
		if(a[i]==6) x6++;
		if(a[i]==7) x7++;
		if(a[i]==8) x8++;
		if(a[i]==9) x9++;
		if(a[i]==0) x0++;
	} 
	for(int i=1;i<=x9;i++) printf("9");
	for(int i=1;i<=x8;i++) printf("8");
	for(int i=1;i<=x7;i++) printf("7");
	for(int i=1;i<=x6;i++) printf("6");
	for(int i=1;i<=x5;i++) printf("5");
	for(int i=1;i<=x4;i++) printf("4");
	for(int i=1;i<=x3;i++) printf("3");
	for(int i=1;i<=x2;i++) printf("2");
	for(int i=1;i<=x1;i++) printf("1");
	for(int i=1;i<=x0;i++) printf("0");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
