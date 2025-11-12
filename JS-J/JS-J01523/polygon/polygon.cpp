#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0;cin>>n;
	int a[n+3],maxn=-1e9;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxn)maxn=a[i];
		sum+=a[i];
	}
	if(n<=3){
		if(sum>2*maxn){
			cout<<1;
		}else{
			cout<<0;
		}
	}else cout<<0;
	return 0;
}
