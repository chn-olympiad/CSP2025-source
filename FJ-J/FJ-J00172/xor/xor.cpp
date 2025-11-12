#include <bits/stdc++.h>
using namespace std;
int a[500005],sum,cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) sum++;
		if(a[i]==1) cnt++;
	}
	if(k==0){
		for(int i=1;i<=n;){
			if(a[i]==1&&a[i]==a[i+1]) sum++,i+=2;
			else i++;
		}
		cout<<sum;
	}
	if(k==1) cout<<cnt;
	return 0;
}
