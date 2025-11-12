#include <bits/stdc++.h>
using namespace std;
int a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int sum=0;
	int sum2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		sort(a+1,a+1+n);
		if(a[1]+a[2]+a[3]>a[3]*2){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}
	return 0;
}

