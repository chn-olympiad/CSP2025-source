#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],d[500005],df[500005],ans,tans;
bool ab[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(k==a[i]||(a[i]==a[i-1]&&ab[i-1]==0)){
			tans++;
			ab[i]=1;
		}
	}
	cout<<tans;
	return 0;
}





