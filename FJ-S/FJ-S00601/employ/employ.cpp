#include<bits/stdc++.h>
using namespace std;
int n,m=1;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	
	cin >> n;
	for(int i=1;i<=n;i++){
		m=(m*i)%998244353;
	} 
	cout << m;
	
	return 0;
}

