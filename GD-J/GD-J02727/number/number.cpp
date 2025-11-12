#include <bits/stdc++.h>
using namespace std;
string n;
bool a[1000005];
int main( ){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	
	for(int i=0;i<=n.size();i++){
		a[n[i]-'0']=true;
	}
	for(int i=9;i>=0;i--){
		if(a[i]){
			cout<<i;
		}
	}
	return 0;
}
