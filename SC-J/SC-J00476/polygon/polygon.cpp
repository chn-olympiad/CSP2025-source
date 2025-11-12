#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[10001];
bool cmp(int a,int b){
	return a>b;
}
//signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}else if(n==3){
		sort(a+1,a+n+1,cmp);
		if(a[2]+a[3]>a[1]){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	
	sort(a+1,a+n+1,cmp);
	if(a[1]==1){
		int cnt=0;
		for(int i=3;i<=n;i++){
			cnt+=i;
		}
		cout<<cnt;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
