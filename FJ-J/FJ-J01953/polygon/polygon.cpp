#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
long long a[5005],n,i,sum=0;
bool b[5005]={};
void l(long long deep,long long max2,long long sum2,long long i2,bool bb[5005]){
	if(deep>i){
		if(deep>i+1){
			return ;
		} 
		if(sum2>2*max2){
			sum++;
			return ;
		}
	}
	for(long long j=i2;j<=n;j++){
		if(bb[j]==1){
			continue;
		}
		bb[j]=1;
		int t=max2;
		max2=max(a[j],max2);
		l(deep+1,max2,sum2+a[j],j,bb);
		max2=t;
		bb[j]=0;
	}
}
int main(){
	freopen("polygon.in","r","stdin");
	freopen("polygon.out","w","stdout");
	cin>>n;
	for(int j=1;j<=n;j++){
		cin>>a[j];
	}
	for(i=3;i<=n;i++){
		l(1,0,0,1,b);
		sum=sum%998244353;
	}
	cout<<sum%998244353;
	return 0;
} 
