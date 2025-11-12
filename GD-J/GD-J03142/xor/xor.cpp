#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
ll n,k,cot=0;
ll arr[500005];
int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	
	bool flag=true;
	
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>arr[i];
		if(flag)if(arr[i]>1)flag=false;
	}
	
	if(flag&&k==0){
		for(int i=1;i<=n;++i){
			if(arr[i]==0){++cot;continue;}
			if(arr[i]==1&&arr[i+1]==1){++cot;++i;}
		} 
		cout<<cot;
		return 0;
	}
	if(flag&&k==1){
		for(int i=1;i<=n;++i)
			if(arr[i]==1)++cot;
		cout<<cot;
		return 0;
	}
	
	ll tmp=0;
	for(int i=1;i<=n;++i){
		tmp=(tmp^arr[i]);
		if(tmp==k){
			++cot;
			tmp=0;
		}
	}
	cout<<cot;
	
 return 0;
}
