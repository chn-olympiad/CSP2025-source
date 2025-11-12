#include<bits/stdc++.h>
using namespace std;
int a[100009],n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int h=0,l=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l+=a[i];
		h=max(h,a[i]);
	}if(l>n*2){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
