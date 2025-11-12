#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500005],b[500005],c;
map<int,bool>f;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((b[j]^b[i-1])==k){
				if(f[i]==0&&f[j]==0){
					c++;
					for(int k=i;k<=j;k++)f[k]=1;
				}
			}
		}
	}
	
	cout<<c;
	return 0;
}//4 2 2 1 0 3
