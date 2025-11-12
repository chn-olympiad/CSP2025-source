#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int s[500005];
int f[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=0;j--){
			if(f[j]<f[i])break ;
			f[i]=max(f[i],f[j]);
			if((s[i]^s[j])==k){
				f[i]=max(f[i],f[j]+1);
				break;
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		cout<<f[i]<<" ";
	}
	cout<<'\n';*/
	cout<<f[n];
	return 0;
}
