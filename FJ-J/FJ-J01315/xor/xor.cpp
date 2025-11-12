#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],js=0,js1=0,js2=0,ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) js++;
		if(a[i]==1||a[i]==0) js1++;
	}
	if(js==n&&k==0){
		cout<<n/2;
		return 0;
	}else if(js1==n&&k<=1){
		for(int i=1;i<=n;i++)
			if(a[i]==k) js2++;
		cout<<js2;
		return 0;
	}else{
		for(int i=1;i<=n;i++){
		int ls=a[i];
		for(int j=1;j<=log2(n);j++){
				ls=ls^a[i+j];
				if(ls==k){
					ans++;
				}
		}
		}
		cout<<ans;
	}
	return 0;
}
