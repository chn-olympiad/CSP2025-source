#include<bits/stdc++.h>
using namespace std;
const int M=5e5+1;
int n,k,a[M],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int rg=0; 
	for(int i=1;i<=n;i++){
		if(a[i]==k) ans++;
		else if(rg^a[i]==k) ans++,rg=0;
		else rg^=a[i];
	}
	cout<<ans<<endl;
	return 0;
}