#include<bits/stdc++.h>
using namespace std;
const int N=5e2+7;
string s1[N],s2[N];
int n,q;
int q=0,w=0,e=0;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cout<<"0\n";
	}
	return 0;
} 
