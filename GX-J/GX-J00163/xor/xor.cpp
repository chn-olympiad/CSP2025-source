#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10;
int n,k,num=0,a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(n<=2&&k==0){
		if(a[1]==0||a[2]==0){cout<<1;return 0;}
		else{cout<<0;return 0;}
	}
	if(n<=2&&k==1){
		for(int i=1;i<=n;++i){
			if(a[i]==1){
				num++;
			}
		}
		cout<<num;
		return 0;
	}
	if(n<=10&&k==0){
		for(int i=1;i<=n;++i){if(a[i]==k){num++;}}
		cout<<num;return 0;
	}
	if(k==0){
		for(int i=1;i<=n;++i){
			if(a[i]==k){num++;}
		}cout<<num;return 0;
	}
	if(k==1){
		for(int i=1;i<=n;++i){
			if(a[i]==k){num++;}
		}cout<<num;return 0;		
	}
	return 0;
}
