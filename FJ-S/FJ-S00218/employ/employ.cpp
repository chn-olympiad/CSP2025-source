#include <bits/stdc++.h>

using namespace std;

const int N=505,mod=998244353;
int n,m,s[N],c[N];
string si;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>si;
	for(int i=0;i<si.size();i++){
		s[i+2]=s[i]+(si[i]-'0'+1)%2;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];	
	}
	return 0;
}
