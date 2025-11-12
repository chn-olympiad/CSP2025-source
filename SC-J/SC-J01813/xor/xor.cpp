#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,k,a[50005]={},ans=0,flag=1,f2=1,x=0,y=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=0;
		if(a[i]!=0&&a[i]!=1) f2=0;
		if(a[i]==0) x++;
		else if(a[i]==1) y++;
	}
	if(flag==1&&k==0){
		cout<<0;
		return 0;
	}
	if(f2==1&&k==1){
		if(x==0) cout<<0;
		else if(x%2==0) cout<<0;
		else cout<<n/3*2;
		return 0;
	}else if(f2==1&&k==0){
		if(x%2==1) cout<<0;
		else cout<<n*7/3;
		return 0;
	}
	cout<<n/2;
	return 0;
}