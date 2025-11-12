#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int su=0,ma=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		su+=a[i];
		ma=max(ma,a[i]);
	}
	if(ma*2<su){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
