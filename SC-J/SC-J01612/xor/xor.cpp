#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[5001],num=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int p;
		if(i==k) num++;
		for(int j=i+1;j<=n;j++){
			p=a[i]^a[j];
			if(p==k) num++;
		}
	}
	cout<<num;
	return 0;
}