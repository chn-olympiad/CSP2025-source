#include<bits/stdc++.h>
using namespace std;
int a[500010],n,b[500010],x,k,c,l=1;
string s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=0;j--){
			if((a[i]^a[j])==k){
				for(int q=0;q<=j;q++){
					b[i]=max(b[i],b[q]+1);
				}
				x=max(x,b[i]);
				break;
			}
		}
	}cout<<x;
	return 0;
}
