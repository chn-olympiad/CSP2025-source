#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,s0=0,s1=0,a[100005],mn,k0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			s0++;
		}
		else if(a[i]==1){
			s1++;
		}
	}
	k0=s1/2+s0/2;
	mn=min(s1,s0);
	if(k==0){
		cout<<k0;
		return 0;
	}
	else if(k==1){
		cout<<mn;
		return 0;
	}
	return 0;
}
