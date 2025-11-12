#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[1000005],b[1000005],ans,t;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		ans=0;
		for(int j=i;j<=n;j++){
			ans^=a[j];
			if(ans==m){
				b[i]=j;
				break;
			}
		}
	}
	ans=0;
	for(int i=1;i<=n;i++){
		if(!b[i])continue;
		k=i;
		for(int j=i+1;j<=b[i];j++){
			k=j	;
			if(b[j]&&b[j]<=b[i]){
				t=1;
				break;
			}
		}
		if(!t)ans++,i=k;
		k=0,t=0;
	}
	cout<<ans;
	return 0;
}

