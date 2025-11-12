#include<bits/stdc++.h>
using namespace std;
long long n,an[500005],ans,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>an[i];
		if(an[i]==k) ans++;
	}
	if(k==0){
		for(int i=2;i<=n;i++){
			if(an[i]==an[i-1]&&an[i]==1) i++,ans++;
		}
	}
	cout<<ans;
	return 0;
}
