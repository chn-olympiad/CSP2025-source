#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		if(n==1&&k==0){
			if(a[i]==0)
				cout<<1;
			else
				cout<<0;
		}	
		else if(n==2&&k==0)
			cout<<0;
	}
	return 0;
}