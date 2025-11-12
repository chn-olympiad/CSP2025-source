#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100; 
long long n,k,a[N],ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==k){
				ans++;
			}
		}
		cout<<ans;
	}else{
		cout<<ans+1;
	}
	return 0;
}
