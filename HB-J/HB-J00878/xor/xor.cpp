#include<bits/stdc++.h>
using namespace std;
int a[500005],p,l,ans=1;
int jie(int n){
	for(int i=1;i<n;i++){
		ans*=i;
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) p++;
		else l++;
	}
	if(k==1){
		cout<<p*l+p;
	}
	else{
		cout<<jie(p)+jie(l)+l;
	}
	return 0;
}
