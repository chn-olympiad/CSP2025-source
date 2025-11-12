#include <bits/stdc++.h>
using namespace std;
const int Max=5e5+5;
int n,m,a[Max];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	bool f1=1,f2=1; 
	a[0]=999;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f1=0;
		if(a[i]!=1&&a[i]!=0) f2=0;
	}
	if(f1==1){
		cout<<n/2;
		return 0;
	}else if(f2==1&&m==0){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0) ans++;
			if(a[i]==1&&a[i-1]==1){
				a[i-1]=0,a[i]=0;
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}else if(f2==1&&m==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) ans++;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
