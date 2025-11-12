#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500150],jl[500150],y=0,ans;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x=a[i];
		if(x==k){
			jl[i]=i;
			continue;
		}
		for(int j=i+1;j<=n;j++){
			x^=a[j];
			if(x==k){
				jl[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(jl[i]!=0 and jl[i]<=y){
			y=jl[i];
		}
		else if(i>y and jl[i]!=0){
			y=jl[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}