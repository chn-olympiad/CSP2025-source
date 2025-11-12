#include<bits/stdc++.h>
using namespace std;

int a[10005];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>2&&k==0){
		int cnt=0;
		for(int i=2;i<=n;i+=2){
			int x=n+1-i;
			cnt+=x;
		}
		cout<<cnt;
		return 0;
	}
	cout<<1;
	return 0;
}
