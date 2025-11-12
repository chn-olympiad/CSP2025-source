#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500010],ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long i=1,h=0;
	while(i<=n){
		for(int j=i;j<=n;j++){
			h=h^a[j];
			if(h==k){
				i=j+1;
				h=0;
				ans++;
				break;
			}
		}
		if(h!=0){
			i++;
			h=0;
		}
	}
	cout<<ans;
	return 0;
}
