#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[500005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	int flag=1,flag2=1,flag1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=0;
		if(a[i]!=1&&a[i]!=0)flag2=0;
		if(a[i]!=0)flag1=0;
	}
	if(flag){
		cout<<n;
	}else if(flag1){
		cout<<n;
	}else if(flag2){
		int cnt0=0,cnt1=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)cnt1++;
			else cnt0++;
			if(i+1<=n&&a[i]==a[i+1]){
				if(a[i]==0)cnt1++;
				else cnt0++;
			}
		}
		cout<<max(cnt0,cnt1);
	}
	return 0;
}
