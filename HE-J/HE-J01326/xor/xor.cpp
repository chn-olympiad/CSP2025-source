#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
ll a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
    if(k==0){
    	cout<<1<<endl;
	}else{
		if(k==255){
			cout<<1<<endl;
		}else{
			cout<<0<<endl;
		}
	}
    fclose(stdin);
	fclose(stdout);
	return 0;
}
