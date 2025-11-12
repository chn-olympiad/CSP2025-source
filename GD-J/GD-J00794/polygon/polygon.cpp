#include<bits/stdc++.h>
using namespace std;
int a[5000],n,m;
void l(int z,int i,int num ,int k){
	if(z>n)	return;
	if(z>2&&num>2*k)	m=(m+1)%998244353;
	for(i;i<n;i++){
		if(num+a[i]>10000)	num=10001;
		else	num+=a[i];
		l(z+1,i+1,num,max(k,a[i]));
	}
	return;
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	l(0,0,0,0);
	printf("%d",m);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

