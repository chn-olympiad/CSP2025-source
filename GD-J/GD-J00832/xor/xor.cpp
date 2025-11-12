#include<bits/stdc++.h>
using namespace std;
int n;
bool taska=1;
long long k,a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(a[i]!=1)taska=0;
	}
    if(taska==1){
    	if(k==1)cout<<n;
    	else if(k==0)cout<<n/2;
    	else cout<<0;
	}
	return 0;
}
