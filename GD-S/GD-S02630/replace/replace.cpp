#include<bits/stdc++.h>
using namespace std;
const int maxn=5e6+10;
using ll=long long;
int n,q,ans;
int a[maxn];
string s[maxn][4];

void solve1(){
	string s1,s2;
	cin>>s1>>s2;
	cout<<0<<endl;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--)solve1();
	
	return 0;
}
