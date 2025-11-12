#include<bits/stdc++.h>
using namespace std;
int n,k,a[5000005],cnt1,cnt2;
bool flag=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++){
		for(int j=1;j<=i;j++) cnt1=cnt1^a[i];
		for(int j=i+1;j<=n;j++) cnt2=cnt2^a[i];
		if(cnt1==k&&cnt2==k&&flag==0){
			cout<<2;
			flag=1;
		}
	}
	if(flag==0) cout<<1;
	return 0;
}
