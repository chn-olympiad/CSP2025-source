#include<bits/stdc++.h>
using namespace std;
const int MAXN=10e5+5;
int a[MAXN],n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool flagA=true;//性质A
	bool flagB=true;//性质B 
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flagA=false;
		if(a[i]!=0&&a[i]!=1) flagB=false; 
	}
	if(flagA){//特殊性质A 
		if(k==1) cout<<n;
		else if(k==0) cout<<n/2;
		else cout<<0;
		return 0;
	}
	if(flagB){//特殊性质B 
		if(k==1){
			int ans=0;
			for(int i=1;i<=n;i++)
				if(a[i]==1) ans++;
			cout<<ans;
		}
		else if(k==0){
			int ans=0,num=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
				if(a[i]==1){
					num++;
					if(num==2) num=0,ans++;
				}
			}
			cout<<ans;
		}
		else cout<<0;
		return 0;
	}
	cout<<0;
	return 0;
} 