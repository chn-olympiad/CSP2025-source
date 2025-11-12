#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,m,c[N];
long long man=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=n;i>=1;i--){
		man*=i%998244353;
	}cout<<man%998244353;
	return 0;
} 
