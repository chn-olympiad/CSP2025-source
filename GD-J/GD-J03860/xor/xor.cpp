#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],x[N],f[N],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		x[i]=x[i-1]^a[i];
	}
	if(n<=10000){
		for(int i=1;i<=n;++i){
			for(int j=i;j<=n;++j){
	//			cout<<(x[j]^x[i-1])<<endl;
				if((x[j]^x[i-1])==k){
					++ans,i=j;
					break;
				}
			}
		}
		cout<<ans;
	}else{
		for(int i=1;i<=n;++i){
			if(a[i]==k) ++ans;
		}
		cout<<ans;
	}
	return 0;
}
