#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long num=1;
    for(int i=0;i<n;i++){
    	num=(num*m)%998244353;
	}
	cout<<num%998244353;
	return 0;
}

