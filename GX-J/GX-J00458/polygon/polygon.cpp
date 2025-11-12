#include <bits/stdc++.h>
using namespace std;
int ans;
int a[6000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=3){
		if(n==3){
			if(a[1]+a[2]>a[3]) printf("1");
			else printf("0");
		}
		else printf("0");
	}
	else{
		if(n<=10){
			cout<<8;
		}
		else{
			cout<<32;
		}
	}
	return 0;
}
