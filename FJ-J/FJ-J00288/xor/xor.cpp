#include<bits/stdc++.h>
using namespace std;
const int N = 5*1e5+5;
int n,k,a[N],maxn;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int tmp=0;
		for(int j=i;j<=n;j++){
			tmp^=a[j];
			if(tmp==k){
				cout<<i<<' '<<j<<endl;
				maxn=max(maxn,j-i-1);
				cout<<i<<' '<<j<<endl;
				tmp=0;
			}
		}
	}
	cout<<maxn;
	return 0;
}
