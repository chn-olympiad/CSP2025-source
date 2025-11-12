#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
int num[1000],n,cnt=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i]; 
	}
	cout<<num[n]+num[n-1];
	
	
	return 0;
}


