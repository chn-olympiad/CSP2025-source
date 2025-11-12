#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100000],b[100000];
int n,k,cnt=0;
void xorr(){
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ans=ans|a[j];
		}
		b[i]=ans;
		if(ans==k){
			cnt++;
		}
		ans=0;
	}
	cout<<cnt;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	xorr();
	return 0;
}
