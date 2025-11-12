#include<bits/stdc++.h>
using namespace std;
int n,a[5005],F;
void f(int T,int sum,int ma,int z){
	if(sum>ma*2&&z>=3){
		F++;
		if(F==998244353)F=0;
	}
	for(int i=T+1;i<=n;i++){
		f(i,sum+a[i],max(ma,a[i]),z+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	f(0,0,0,0);
	cout<<F;
}
