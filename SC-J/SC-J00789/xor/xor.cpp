#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a,b,ans,c;ans=0;
	cin>>n>>k;
	cin>>b;
	a=b;
	for(int i=2;i<=n;i++){
		cin>>b;
		c=b^b;
		if(c==k){
			ans++;
			a=b;
		}else{
			a=a^b;
			if(a==k){
				ans++;
				a=b;
			}
		}
	}
	cout<<ans;
	
	
	
	return 0;
}