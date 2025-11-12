#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k;
int a[N];
map<int,int> sum;
bool T=true;
int mx,ans;
int f(){
	int ans=0;
	for(int i=0;i<=mx;i++)
		ans+=sum[i]/2;
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[a[i]]++;
		mx=max(mx,a[i]);
		if(a[i]!=1) T=false;
		ans+=(a[i]==k?1:0);
	}
	if(!k){
		cout<<f();
		return 0;
	}
	cout<<ans;
	return 0;
}