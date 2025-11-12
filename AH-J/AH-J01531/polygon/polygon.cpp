#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[5010],n,maxn=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	maxn*=2;
	if(a[1]+a[2]+a[3]>maxn){
		cout<<"1";
	}
	return 0;
}
