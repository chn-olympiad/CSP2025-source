#include<bits/stdc++.h>
using namespace std;
long long n,a[5100],ans,big,maxn;
bool cmp(int x,int y){
	return x<y;                       
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		big+=a[i];
		maxn=max(maxn,a[i]);
	}
	if(big>(maxn*2)){
		ans++;
	}
	cout<<ans;
	return 0;
}
