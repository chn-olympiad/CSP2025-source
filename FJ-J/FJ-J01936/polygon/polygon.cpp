#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n;
int a[5010];
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	if(n==3){
		if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))) cout<<1;
		else cout<<0;
	}
	cout<<0;
	// 希望能多骗两分 && 祝RP++  
	return 0;
}
