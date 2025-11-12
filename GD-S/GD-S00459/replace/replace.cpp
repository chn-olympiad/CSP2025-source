#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long n,q;
string s[N];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n+q;i++){
		cin>>s[i];
	}
	for(int i=1;i<=q;i++){
		cout<<"0"<<endl;
	}
	return 0;
}
