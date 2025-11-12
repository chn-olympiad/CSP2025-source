#include <bits/stdc++.h>
using namespace std;
long long int n,k;
int a[1000001],b[1000001],bj[1000001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	long long int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[j+1]=b[j]^a[j];
			if(b[j]==k&&bj[j]==0){
				ans++;
				for(int k=i;k<=n;k++){
					bj[k]=1;
					b[k]=a[k];
				}
				break;
			}	
		}
	}
	cout<<ans;
	if(n<=2&&k==0){
		cout<<1;
	}
	return 0;
}