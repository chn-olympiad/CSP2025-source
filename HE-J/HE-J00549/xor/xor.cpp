#include<bits/stdc++.h>
using namespace std;
long long b[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,ret=0,l=1,a;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a;
		for(int j=l;j<=i;j++){
			b[j]=b[j]^a;
			if(b[j]==k){
				l=i+1;
				ret++;
				break;
			}
		}
	}
	cout<<ret;
	return 0;
}
