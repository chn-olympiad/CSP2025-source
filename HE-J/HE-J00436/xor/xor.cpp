#include<bits/stdc++.h>
using namespace std;
int n,k,a[200005],cnt=0;
bool f=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) if(a[i]!=1) f=0;
	if(f==1){
		if((k!=0)&&(k!=1)) cout<<0;
		else if(k==0) cout<<n%2;
		else cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++) if(a[i]==1) cnt++;
	if(k==0) cout<<n-cnt;
	else if(k==1) cout<<cnt;
	else cout<<0;
	return 0;
}
