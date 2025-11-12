#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5010],maxx=0,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(a[i],maxx);
		sum=sum+a[i];
	}
	if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>=a[1]&&sum>maxx*2){
		cout<<"1";
	}else{
		cout<<"0";
	}
    return 0;
}
