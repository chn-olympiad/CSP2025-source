#include<bits/stdc++.h>
using namespace std;
int a[5005],n,ans=0,mod=998244353;
bool ab(int x,int y){
	return x>y;
}
void f(int x,int y,int z){
	if(y>n){
		if(z>x) ans=(ans+1)%mod;
		return;
	}
	f(x,y+1,z);
	f(x,y+1,z+a[y]);
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int c=1;c<=n;c++) cin>>a[c]; 
	sort(a+1,a+1+n,ab);
	for(int c=1;c<=n-2;c++){
		f(a[c],c+1,0); 
	}
	cout<<ans;
	return 0;
} 
