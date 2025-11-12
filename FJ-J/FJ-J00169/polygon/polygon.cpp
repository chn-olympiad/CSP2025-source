#include<bits/stdc++.h>
using namespace std;
int a[5005]={0},c[5005],n,sum=0;
int f(int m,int num,int mi,int su,int mx){
	int s=0;
	if(num>m){
		if(su>2*mx)return 1;
		else return 0;
	}
	for(int i=mi+1;i<=n;++i){
		c[num]=i;
		s+=f(m,num+1,i,su+a[i],max(a[i],mx));
	}
	return s%998244353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=3;i<=n;++i)sum+=f(i,1,0,0,0);
	cout<<sum;
	return 0;
}
