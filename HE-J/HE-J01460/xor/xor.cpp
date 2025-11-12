#include<bits./stdc++.h>
#define int long long
using namespace std;;
int n,k,a[500010];
int b[500010],sum,ans;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	int l=1;
	for(int i=1;i<=n;i++){
		for(int j=l;j<=i;j++){
			int x=b[i]^b[j-1];
			if(x==k){
				l=i+1;
				sum++;
				break;
			}
		}
	}
	cout<<sum;
	return 0;
}
