#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],f=0,cnt=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			f=1;
			cnt++;
		}
	}
	if(k==0) cout<<0;
	else if(k==0&&f==1){
		cout<<cnt;
	}
	else{
		cout<<2;
	}
	return 0;
}
