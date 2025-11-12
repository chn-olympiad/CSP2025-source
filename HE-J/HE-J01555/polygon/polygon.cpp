#include <bits/stdc++.h>
using namespace std;
int a[5010];
int main(){
	freopen("polygon.in",'w',stdin);
	freopen("polygon.out",'r',stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[1]+a[2]>a[3]||a[2]+a[3]>a[1]||a[3]+a[1]>a[2]){
		cout<<1;
	}
	return 0;
}
