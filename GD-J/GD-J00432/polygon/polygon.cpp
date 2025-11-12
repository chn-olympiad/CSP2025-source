#include<iostream>
#include<algorithm>
using namespace std;
int n,a[5005],b[5005];
long long ans;
bool f[5005];
void pd(int x){
	int maxl=0,sum=0;
	for(int i=0;i<x;i++){
		maxl=max(maxl,a[b[i]]);
		sum+=a[b[i]];
	}
	if(sum>maxl*2) ans++;
 
}
void qpl(int x,int k,int y){
	if(k==x){
		pd(x);
		return;
	} 
	for(int i=y;i<n;i++){
		if(f[i]==0){
			b[k]=i;
			f[i]=1;
			qpl(x,k+1,i+1);
			f[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		qpl(i,0,0);
	}
	cout<<ans%998244353;
	return 0;
} 

