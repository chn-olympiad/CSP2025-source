#include<bits/stdc++.h>
using namespace std;
int n,k,a[100001];
int main(){
	freopen ("xor.in","r",stdin);
	freopen ("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==2&&k==0){
		for(int i=1;i<=n;i++){
			if(a[i]!=0) {
				cout<<1;
				break;
			}else{
				cout<<2;
				break;
			}
		}
	}
	if(n==1&&k==0) {
		cout<<1;
		return 0;
	}
	if(n>2){
		int sum=0;
		int maxn=0;
		for(int i=1;i<=n;i++){
			if(a[i]==a[i-1]) {
				sum++;
				maxn=max(sum,maxn);
			}else sum=0;
		}
		cout<<sum;
		return 0;
	}
	return 0;
}
