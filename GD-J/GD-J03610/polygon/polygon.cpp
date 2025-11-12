#include<bits/stdc++.h>
using namespace std;
int n,a[500010],cnt;
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==3){
		int maxx=a[1],mxw=1;
		for(int i=1;i<=3;i++){
			if(a[i]>maxx){
				maxx=a[i];
				mxw=i;
			}
		}
		if(a[1]+a[2]+a[3]>maxx*2){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
}
