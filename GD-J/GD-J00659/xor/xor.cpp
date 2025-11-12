#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
int a[maxn];
bool flag1,flag2;
int ans,n,k,num1,num0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	flag1 = flag2 = true;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag1 = false;
		if(a[i]>1)flag2 = false;
		if(a[i]==1)num1++;
		if(a[i]==0)num0++;
	}
	if(flag1)cout<<n/2,exit(0);
	if(flag2){
		if(k==1){ 
			cout<<num1,exit(0);
		}else{
			for(int i = 1;i<=n;i++){
				if(a[i]==1&&a[i-1]==1)ans++;
			}
			cout<<ans+num0,exit(0);
		}
	}
}
