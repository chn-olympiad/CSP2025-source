#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
long long a[N],k,he[1010],f[1010];
bool flag1=1,ok[1010][1010];	
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag1=0;
	}
	a[0]=-1;
	if(flag1){
		cout<<n/2;
		return 0;
	}else{
		for(int i=1;i<=n;i++)
			he[i]=he[i-1]^a[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				long long x=he[i]^he[j-1];
				if(x==k){
					ok[j][i]=1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(ok[j][i]==1){
					f[i]=max(f[i-1],f[j-1]+1);
				}else{
					f[i]=max(f[i],f[j]);
				}
			}
		}
		cout<<f[n];
	}
		
	return 0;
}


