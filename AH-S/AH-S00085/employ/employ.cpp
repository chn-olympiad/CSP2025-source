#include<bits/stdc++.h>
using namespace std;
int n,m,b,s=1;
string a;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    
    cin>>n>>m;
    cin>>a;
    for (int i=1;i<=n;i++) cin>>b;
    for (int i=1;i<=n;i++){
		s*=i;
		s%=85959736;
	}
	cout<<s;
    return 0;
}
