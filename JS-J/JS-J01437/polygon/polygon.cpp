#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long knum;
int n,a[5005],qwp[5005];
void awa(int p,int mul,int qwp[5005],int k,long long num,int maxn){
	if(mul==p){
		if(num>maxn*2){
			knum++;
			knum%=998244353;
		}
		return ;
	}
	else{
		for(int i=k+1;i<=n-p+mul+1;i++){
			qwp[mul+1]=a[i];
			awa(p,mul+1,qwp,i,num+a[i],max(maxn,a[i]));
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		awa(i,0,qwp,0,0,0);
	}
	cout<<knum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
