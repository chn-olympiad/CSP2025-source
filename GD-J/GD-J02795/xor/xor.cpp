#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,k,ans;
long long a[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int v=0^0;
	bool p=1;
	bool q=1;
	long long g=0,s=0;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		if(a[i]!=1) p=0;
		if(a[i]!=1 && a[i]!=0) q=0;
		if(a[i]==1) g++;
		else if(a[i]==0) s++;
	}
	if(n==1 && a[1]!=k){
		cout<<0;
		return 0;
	}
	if(n==2 && k==0 && p){
		if(a[1]==0 && a[2]==0){
			cout<<2;
			return 0;
		}
		if(a[1]==0 || a[2]==0){
			cout<<1;
			return 0;
		}
		if(a[1]^a[2]==0 || a[2]^a[1]==0){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	if(p && k==0){
		cout<<n/2;
		return 0;
	}
	if(p && k==1){
		cout<<n;
		return 0;
	}
	if(p && k!=1 && k!=0){
		cout<<0;
		return 0;
	}
	if(k==0 && q){
		cout<<s;
		return 0;
	}
	if(k==1 && q){
		cout<<g;
		return 0;
	}
	
	long long sum,t;
	for(int i=1; i<=n; i++){
		t=i;
		if(a[i]==k){
			ans++;
			continue;
		}
		else{
			sum=a[i];
			break;
		}
	}
	for(int i=t; i<=n; i++){
		sum^=a[i];
		if(sum==k){
			ans++;
			sum=a[i+1];
			i++;
		}
	}
	cout<<ans+1;
	return 0;
}
