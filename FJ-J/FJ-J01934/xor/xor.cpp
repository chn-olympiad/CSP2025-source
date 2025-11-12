#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 5e5 + 5;
int Q ;
int n,k;
int a[N];
int ans;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	int b=0;
	for(int i=1;i<=n;i++){
		if(b==0){
			b=a[i];
			//cout<<"R:"<<i;
			if(b==k){
				b=0;
				ans++;
				//cout<<"   L:"<<i<<endl;
			}
		}
		else {
			if(b|a[i]==k){
				b=0;
				ans++;
				//cout<<"   L:"<<i<<endl;
			}
			else b=b|a[i];
		}
	}
	cout<<ans;
//	        ^-----^
	return ( Q ^ Q );
//	        -------
}
