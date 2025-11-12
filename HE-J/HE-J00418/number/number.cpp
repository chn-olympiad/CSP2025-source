#include<bits/stdc++.h>
using namespace std;
string a;
const int N=1e7+10;
long long f[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]<'A')f[a[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=f[i];j>0;j--)cout<<i;
	}
	return 0;
}
