#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int p1=0,p2=1;
	int cnt=0,ans=0;
	while(p2<=n){
		for(int i=p2;i>p1;i--){
			cnt^=a[i];
			if(cnt==k){
				ans++;
				p1=p2;
				break;
			}
		}
		cnt=0;
		p2++;
	}
	cout<<ans;
	return 0;
}