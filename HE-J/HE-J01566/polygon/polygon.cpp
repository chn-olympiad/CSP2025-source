#include<bits/stdc++.h>
using namespace std;
int n,a[5002];
long long ans=0;
void dg(int i,int cnt,int mx,int s){
	ans+=s>2&&(cnt>mx*2);
	//cout<<cnt<<' '<<mx<<' '<<s<<endl;
	if(i>=n){
		return;
	}
	for(;i<n-max(0,2-s);i++){
		dg(i+1,cnt+a[i],max(mx,a[i]),s+1);
	}
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	dg(0,0,0,0);
	cout<<ans%998244353;
	return 0;
}
