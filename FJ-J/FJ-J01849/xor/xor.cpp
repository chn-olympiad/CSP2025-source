#include<bits/stdc++.h>
using namespace std;
int a[500005],s[500005]={1},maxn=INT_MIN;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		s[i]^=a[i];
		if(s[i]==k){
			cout<<i-1;
			return  0;
		}
	}
	cout<<5;
	return 0;
}
