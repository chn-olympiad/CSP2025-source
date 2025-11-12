#include <bits/stdc++.h>
using namespace std;
long long MOD=998244353;
int a[5010];
int n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n;	cin>>n;	
	for(int i=1 ; i<=n ; i++){
		cin>>a[i];
	}
	if(n==3){
		int maxi;
		maxi=max(a[1],max(a[2],a[3]));
		int sum=a[1]+a[2]+a[3];
		if(sum > maxi*2)	cout<<1;
		else	cout<<0;
		return 0; 
	}
	if(n==4){
		int maxi,cnt=0,sum;
		maxi=max(a[1],max(a[2],a[3]));
		sum=a[1]+a[2]+a[3];
		if(sum > maxi*2)	cnt++;
		sum=a[1]+a[2]+a[4];
		if(sum > maxi*2)	cnt++;
		sum=a[1]+a[3]+a[4];
		if(sum > maxi*2)	cnt++;
		sum=a[2]+a[3]+a[4];
		maxi=max(a[4],max(a[2],a[3]));
		if(sum > maxi*2)	cnt++;
		sum=a[1]+a[2]+a[3]+a[4];
		maxi=max(max(a[1],a[4]),max(a[2],a[3]));
		if(sum > maxi*2)	cnt++;
		cout<<cnt;
		return 0; 
	}
	
	return 0;
}
