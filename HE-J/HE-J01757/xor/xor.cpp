#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5;
int n,k,a,b,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a==k)ans+=1,b=0;
		else{
			b^=a;
			if(b==k)ans+=1,b=0;
		}
	}
	cout<<ans<<endl;
	return 0;
}
