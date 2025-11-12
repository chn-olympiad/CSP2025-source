#include <bits/stdc++.h>
using namespace std;
long long n,m,nm,op,sum,sum1,i,j,k,a[1000005],b[1000005],mid,ans,max1=114514114514114514,min1=-114514114514114514;
string s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	op=1;
	for(i=1;i<=n*m;i++){
		cin>>k;
		if(i==1)nm=k;
		else if(nm<k)op++;
	}
	if(op%n!=0)j=1;
	nm=op/n+j;//目前的列数 
	if(nm%2==0){
		nm=n+1-(op-((nm-1)*n));//目前的行数 
	}else{
		nm=n-((nm*n)-op);//目前的行数 
	}
	printf("%lld %lld",op/n+j,nm);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
