#include<bits/stdc++.h>
using namespace std;
long long a[15];
string t;
int main(){
	freopen("number.in","r",stdin);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	for(long long i=0;i<t.size();i++){
		if(t[i]>='0'&&t[i]<='9'){
			a[t[i]-'0']++;
		}
	}
	for(long long i=9;i>=0;i--){
		long long cu=a[i];
		for(long long j=cu;j>0;j--){
			cout<<i;
		}
	}
	freopen("number.out","w",stdout);
	return 0;
}
