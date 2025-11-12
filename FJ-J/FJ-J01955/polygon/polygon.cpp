#include<bits/stdc++.h>
using namespace std;
int a[25000005],ab[25000005],ac[25000005],shu[5005];
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,w=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>shu[i];
	}
	sort(shu+1,shu+1+n,cmp);
	for(int i=1;i<=n;++i){
		w+=shu[i];
		for(int j=w;j>=1;--j){
			if(j>shu[i]*2){
				a[j]=(ab[j-shu[i]]+a[j])%998244353;	
			}//cout<<ab[j]<<" ";
			ab[j]=(ab[j]+ab[j-shu[i]])%998244353;
		}
		ab[shu[i]]++;
		//cout<<endl;
	}
	long long o=0;
	for(int i=1;i<=w;++i){
		o=(o+a[i])%998244353;
		
	}
	cout<<o;
	return 0;
}
