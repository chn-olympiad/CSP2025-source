#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+20;
ll n,k,a[N];
ll s1,s2,s3;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) s1++;
		if(a[i]==1) s2++;
		if(a[i]==0) s3++;
	}
	if(s1!=0){
		cout<<s1;
		return 0;
	}
	if(k>1){
		cout<<0;
		return 0;
	}
	if(k==1){
		cout<<s2;
		return 0;
	}
	if(k==0){
		cout<<s2/2+s3;
		return 0;
	}
	return 0;
}
