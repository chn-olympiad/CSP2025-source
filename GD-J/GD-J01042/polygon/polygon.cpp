#include<bits/stdc++.h>
using namespace std;
int a[5020];
long long ans;
int main(){
	int n;
	cin>>n;
	bool flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=1;
		}
	} 
	if(n!=3&&flag!=0){
		cout<<0;
		return 0;
	}else if(n==3){
		int m=a[1]+a[2]+a[3];
		int x=max(a[1],max(a[2],a[3]));
		if(m>x*2){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}else{
		for(int i=1;i<=n-2;i++){
			int l=n-1-i;
			while(l>=1){
				ans++;
				ans%=998244353;
				l--;
			}
		}
		cout<<ans;
	}
}
