#include<bits/stdc++.h>
using namespace std;
int main(){
	freeopen("polygon.in","w",stdin);
	freeopen("polygon.out","r",stdout);
	int n,s,da=0,a[100];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		a[i]=s;
	}for(int i=1;i<=n;i++){
		if(a[i]>=da){
			da=a[i];
		}
	}if(da*2<a[1]+a[2]+a[3]){
		cout<<1;
	}else{
		cout<<0;
	}
}
