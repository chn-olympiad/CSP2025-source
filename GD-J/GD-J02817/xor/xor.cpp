#include <bits/stdc++.h>
using namespace std;
int n,k,i,j,p,l,ans;
int a[500005],b[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	l=1;
	for(i=1;i<=n;i++){
		b[i]=b[i-1]^a[i];
		p=b[i];
		for(j=l;j<=i;j++){
			if(p==k){
				ans++;
				l=i+1;
				b[i]=0;
				break;
			}
			p^=a[j];
		}
	}
	cout<<ans;
	return 0;
}

