#include<bits/stdc++.h>
using namespace std;
long long a[5000010],cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	if(n==1){
		if(a[1]>a[i]*2) cnt++;
	}else if(n==2){
		if(a[1]+a[2]>a[2]*2) cnt++;
	}else if (n==3){
		if(a[1]+a[2]+a[3]>a[3]*2) cnt++;
	}cout<<cnt;
	return 0;
}
