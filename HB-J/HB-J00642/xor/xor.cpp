#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,sum[N],a[N],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		sum[i]=a[i]^sum[i-1];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((sum[i]^a[j])==m){
				cnt++;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}
