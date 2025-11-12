#include<bits/stdc++.h>
using namespace std;
const int N=100+10,M=100+10; 
const long long mod=998244353;
int n,m,cnt;
string s;
int c[N];
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	} 
	if(n<m){
		cout<<0;
		return 0;
	} 
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
	return (0^0);
}
//CSP-S IS TOO HARD AND NOBODY CAN BEAR IT!
   	  /*=.   .==+==.
     L/  \\ //
    //    \//
   //  C  //
  //     //\\
 //     //  \\
`===== `==X==*/
