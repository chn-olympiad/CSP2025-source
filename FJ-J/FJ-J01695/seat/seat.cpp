#include<bits/stdc++.h> 
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
long long n,m;
long long a[150];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int q=0;q<n*m;q++){
		scanf("%d",&a[q]);
	}
	long long p,r=a[0];
	sort(a+0,a+n*m);
	for(int q=0;q<n*m;q++){
		if(a[q]==r){
			p=q;
			break;
		}
	}	
	p=n*m-p;
	if(p%n==0){
		printf("%d %d",p/n,n);
	}
	else{
		printf("%d ",p/n+1);
		if((p/n+1)%2==1){
			printf("%d",p%n);
		}
		else{
			printf("%d",n-p%n+1);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
