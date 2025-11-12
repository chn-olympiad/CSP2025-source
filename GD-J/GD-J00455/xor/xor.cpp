#include<bits/stdc++.h>
using namespace std;
const int N=1e8;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0,sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		if(sum==k){
			++ans;
			sum=0;
		}
		int x;
		cin>>x;
		sum^=x;
	}
	if(sum==k) ++ans;
	cout<<ans;
	return 0;
} 
