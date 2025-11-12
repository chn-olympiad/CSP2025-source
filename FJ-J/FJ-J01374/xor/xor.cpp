#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[200005];
int maxn=0;
int frog=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0&&frog==1) frog=2;
		else if(a[i]!=1&&a[i]!=0) frog=0;
	}
	if(frog==1){
		cout<<n/2;
		return 0;
	}	
	if(frog==2){
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				maxn++;
				continue;
			}
		}
		cout<<maxn;
		return 0;
	}
	return 0;
}
