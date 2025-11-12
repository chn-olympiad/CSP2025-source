#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,k;
int a[maxn];
int cnt1,cnt0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			cnt1++;
		}
		if(a[i]==0){
			cnt0++;
		}
	}
	if(k!=0 and k!=1){
		cout<<0;
		return 0;
	}
	if(k==1){
		cout<<cnt1;
	}
	else{
		cout<<cnt1/2;
	}
} 

