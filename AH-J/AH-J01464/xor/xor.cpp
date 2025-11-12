#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long int n,k;
long long int a[N],x[N];
long long int t[N];
int main(){
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x[i]=a[i]^x[i-1];
	}
	int ans=0;
	t[0]++;
	for(int i=1;i<=n;i++){
		if(t[x[i]^k]||a[i]==k){
			ans++;
			memset(t,0,sizeof(t));
		}
		t[x[i]]++;
	}
	cout<<ans;
	return 0;
}
