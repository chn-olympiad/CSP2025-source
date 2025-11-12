#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,num[N],a[N],b[N],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	b[0]=k;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		a[i]=a[i-1]^num[i];
		b[i]=a[i]^k;
	}
	int l=0,r=1;
	while(r<=n){ 
		for(int i=l;i<r;i++){
			if(a[r]==b[i]){ 
				l=r,ans++;
				break;
			}
		}
		r++;
	}
	cout<<ans;
	return 0;
}
