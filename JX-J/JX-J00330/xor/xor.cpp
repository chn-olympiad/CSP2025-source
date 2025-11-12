#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,c=0;
int a[N];
int q[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q[i]=q[i-1]^a[i];
	}
	int l=1;
	for(int i=1;i<=n;i++){
		for(int j=l;j<=i;j++){
			if((q[i]^q[j-1])==k){
				c++;
				l=i+1;
				break;
			}
		}
	}
	cout<<c;
	return 0;
}

