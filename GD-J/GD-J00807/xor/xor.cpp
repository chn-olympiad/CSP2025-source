#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
typedef long long ll;
ll n,k,a[maxn],s1,s0,sum;
bool lg=1,llg=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xot.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]==k)sum++;
		if(a[i]==1)s1++;
		if(a[i]==0)s0++;
		if(a[i]!=1)lg=0;
		if(a[i]!=1 && a[i]!=0)llg=0;
	}
	if(k==0 && lg){
		cout<<n/2;
		return 0;
	}
	if(llg && k==0){
		cout<<s0+s1/2;
		return 0;
	}
	else if(llg && k==1){
		cout<<s1;
		return 0;
	}
	cout<<sum;
	return 0;
}
