#include<bits/stdc++.h>
using namespace std;
int n,i,a[5011],ans;
const int tldhz=998244353;
void sc(int x,int y,int z,int w){
	if(x>n){
		if(w>2&&y>z) ans++,ans%=tldhz;
		return ;
	}
	sc(x+1,y+z,a[x],w+1);
	sc(x+1,y,z,w);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+1+n);
	sc(1,0,0,0);
	cout<<ans;
	return 0;
}

