#include<bits/stdc++.h>
using namespace std;
int n,k,cnt,cnt1,ans;
const int N=1e6+10;
int a[N],sum[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int f=0,f1=0,cnt2=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x==k)cnt1++;
		if(x!=1)f1=1;
		if(x!=1||x!=0)f=1;
		if(x==1)cnt2++;
		if(x!=0)a[++cnt]=x;
	}
	if(f1==0&&k==0){
	cout<<n/2;
	return 0;
 	}
 	else if(f==0){
 		cout<<cnt2;
 		return 0;
	 }
	else cout<<cnt1; 
	
	return 0;
}