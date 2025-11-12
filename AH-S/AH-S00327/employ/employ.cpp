#include<bits/stdc++.h>
using namespace std;
long long n,m,a[501],q=1;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>s;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		q*=i;
	}
	cout<<q;
    return 0;
}
