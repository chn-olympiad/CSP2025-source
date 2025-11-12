#include<iostream>
#define MOD 998244353
using namespace std;
long long n,a[5005],f[5005],pre[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	f[1]=f[2]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=2){
			pre[i]=pre[i-1]+a[i];
		}else{
			pre[i]=a[i];
		}
	} 
	for(int i=3;i<=n;i++){
		
		
	}
	
	
	return 0;
}
