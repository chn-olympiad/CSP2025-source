#include<bits/stdc++.h>
using namespace std;
long long n,k,a[200005],t=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[i]&a[j]==k) t++;
		}
	}
	cout<<t;
	return 0;
}


