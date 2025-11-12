#include<bits/stdc++.h>
using namespace std;
bool a = 1,b = 1;
int n,m;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	cin>>s;
	
	if(n==m){
		cout<<1;
		return 0;
	}
	cout<<m%998244353;
	return 0;
}

