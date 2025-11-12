#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],n,k,cnt=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	int last=0;
	for(int i=1;i<=n;i++){
		for(int j=last+1;j<=i;j++){
			if((b[i]^b[j-1])==k){
				cnt++;
				last=i;
				break;
			}
		}
	}
	cout<<cnt;
}