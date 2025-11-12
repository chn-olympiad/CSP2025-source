#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long int n,l,a[100001],da=0;
	cin>>n>>l;
	for(long long int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long int i=1;i<=n;i++){
		int tot=0;
		for(long long int j=i;j<=n;j++){
			long long int ans=i;
			for(long long int k=i;k<=j;k++){
				ans^=a[k];
				if(ans==l){
					tot++;
					break;
				}
			}
		}
		if(tot>da){
			da=tot;
		}
	}
	cout<<da;
	return 0;
}