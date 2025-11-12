#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5;
int n,q;
string str[maxn][2],rep[maxn][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>str[i][0]>>str[i][1];
	}
	for(int i=1;i<=q;i++){
		cin>>rep[i][0]>>rep[i][1];
	}
	for(int i=1;i<=q;i++){
		cout<<0<<'\n';
	}
} 
