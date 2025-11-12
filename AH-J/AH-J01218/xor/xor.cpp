#include<bits/stdc++.h>
using namespace std;
int a[10010];
bool f[10010];
long long n,k;
long long ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]==k){
			ans++;
			f[i]=1;
		}
	}
	cout<<ans;
	return 0;
}
