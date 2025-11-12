#include<iostream>
using namespace std;
int a[5010];
int n,ansn;
void f(int k,int ans,int maxn,int d,bool p){
	if((ans>2*maxn)&&d>=3&&p){
		ansn++;
		ansn%=998244353;
//	cout<<k<<" "<<ans<<" "<<maxn<<" "<<d<<endl;
	}
	if(k==n){
		return;
	}
	f(k+1,ans+a[k],max(maxn,a[k]),d+1,1);
	f(k+1,ans,maxn,d,0);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	f(0,0,0,0,0);
	cout<<ansn;
	return 0;
}
