#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e5+5;
int a[N];

signed main(){

	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n;
	int k;
	cin>>n>>k;
	bool f1=true;
	bool f2=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f1=false;
		if(a[i]<0||a[i]>1) f2=false;
	}
	if(f1==true&&k==0){
		cout<<n/2;
		return 0;
	}
	if(f1=true&&k==1){
		cout<<n;
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int num=a[i];
			for(int l=i+1;l<=j;l++){
				num^=a[l];
			}
			if(num==k){
				ans++;
			}
		}
	}
	cout<<ans;
	
	
	
	return 0;
}
