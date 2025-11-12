#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long w=a[i],v=0,d,e=a[i]^0;
		if(e==k){
			ans++;
		}else{
			for(int j=i+1;j<=n;j++){
				int eee=w^a[j];
				if(eee==k){
					ans++;v=1;d=j;
					break;
				}else{
					w^=a[j];
				}
			}
			if(v==1){
				i=d;
			}
		}
	}
	cout<<ans;
	return 0;
}
