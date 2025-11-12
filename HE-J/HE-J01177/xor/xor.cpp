#include<bits/stdc++.h>
using namespace std;
const int maxn=256;
int n,k,l,r;
int a[maxn];
int main(){
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(k==0){
			if(a[i]==1){
				cout<<1;
			}
		}
	}
	return 0;
}
