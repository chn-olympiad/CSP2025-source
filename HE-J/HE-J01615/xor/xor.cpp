#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,k,ans;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=k){
			int m=a[i];
			for(int j=i+1;j<=n;j++){
				m^=a[j];
				if(m==k){
					i=j+1;
					break;
				}
			}ans++;
		}else ans++;
	}cout<<ans;
	return 0;
}
