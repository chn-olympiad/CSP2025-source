#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],s[N],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1,jj=0;i<=n;i++){
		bool cs=0;
		for(int j=jj;j<i;j++){
			//cout<<i<<' '<<j<<' '<<(s[j]^s[i])<<endl;
			if(cs) continue;
			if((int)(s[j]^s[i])==k){
				ans++;
				cs=1;
			}
		}
		if(cs){
			jj=i;
			//cout<<endl;
		}
	}
	cout<<ans;
	return 0;
}
