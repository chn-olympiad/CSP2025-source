#include<iostream>
#include<cstdio>
using namespace std;
int n,a[5001],sum,c1;
void go(int i,int c,int s,int da){
	if(c==c1){
		if(2*da<s){
			sum++;
			sum=sum%998244353;
		}
		return;
	}
	for(int j=i+1;j<=n;j++){
		go(j,c+1,s+a[j],max(da,a[j]));
	}
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=3;k<=n;k++){
		c1=k;
		for(int p=1;p<=n-k+1;p++){
			go(p,1,a[p],a[p]);
		}
	}
	cout<<sum;
	
	
	return 0;
} 
/*
1=拿下！

注意freopen注释 
4. 40?降时间复杂度！！！！ 
*****取模998244353
随机选取3个及以上的数，其他的数之和大于最大值即为一种方案； 						
*/