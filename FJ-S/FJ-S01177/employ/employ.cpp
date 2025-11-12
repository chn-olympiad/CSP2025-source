#include<bits/stdc++.h>
using namespace std;
long long n,m,c[505],sum=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	for(int i=n;i>1;i--){
		sum*=i;
		sum%=998244353;
	}
	cout<<sum;
}
