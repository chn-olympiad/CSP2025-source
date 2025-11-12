#include<bits/stdc++.h>
using namespace std;
int n,k,flag=1,ans;
int num[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>num[i];
		if (num[i]!=1) flag=0;
	}
	if(k==0&&flag) {
		for (int i=2;i<=n;i+=2){
			ans+=i;
		}
		cout<<ans;
	}
	return 0;
}
