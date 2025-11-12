#include<iostream>
#include<cstdio>
using namespace std;
const int maxs=0x7fffffff;
unsigned int n,k,value[500010],map[500010],sum=0;
unsigned int SumXor(unsigned int l,unsigned int r){
	bool bsum[20];
	unsigned int vl=value[l];
	for(int i=19;i>=0;i--){
		bsum[i]=vl%2;
		vl/=2;
	}
	for(int i=l+1;i<=r;i++){
		unsigned int vi=value[i];
		for(int j=19;j>=0;j--){
			bsum[j]=(bsum[j]!=vi%2);
			vi/=2;
		}
	}
	unsigned int sum=0;
	for(int i=0;i<=19;i++)sum=sum*2+bsum[i];
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>value[i];
		map[i]=maxs;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(SumXor(i,j)==k){
				map[i]=j;
				break;
			}
		}
		if(map[i]!=maxs){
			sum++;
			i=map[i];
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
