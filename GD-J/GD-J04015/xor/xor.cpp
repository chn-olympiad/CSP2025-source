#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		a[i]=x^a[i-1];
	}
	int j=0,ans=0;
	for(int i=1;i<=n;i++){
		int jj=j+1;
		while(jj<=i){
			int o=a[i]^a[jj-1];
			if(o==k){
				ans++;
				j=i;
				break;
			}
			jj++;
		}
	}
	cout<<ans;
	return 0;
}
