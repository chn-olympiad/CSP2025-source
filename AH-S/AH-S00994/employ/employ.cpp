#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <queue>
#include <deque>
#include <cstring>
#include <string>
using namespace std;
int n,m;
string s;
int a[400005];
int ans;
int main(){

    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
	    cin>>a[i];
	}
	ans=m;
	for(int i=2;i<=m;i++){
		ans=ans*m%998244353;
	}
	cout<<ans;
    return 0;

}
