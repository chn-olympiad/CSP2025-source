#include<bits/stdc++.h>
using namespace std;
int a[100000],ans=0,n;
void dg(int num,int max_l,int all_l,int all_num){
	if(num>n){
		if(all_l>max_l*2&&all_num>=3)ans++;
		return;
	}
	for(int i=0;i<=1;i++){
		if(i)max_l=max(max_l,a[num]);
		dg(num+1,max_l,all_l+a[num]*i,all_num+i);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dg(1,0,0,0);
	cout<<ans%998244353;
	return 0;
}
