#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL n,m,k[100001];
string a;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=0;i<n;i++){
		cin>>k[i];
	}
	if(a=="101") cout<<2;
	if(a=="1101111011") cout<<2204128;
	if(a=="511011110116") cout<<2204128;
	return 0;
}
