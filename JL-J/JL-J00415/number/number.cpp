#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[15];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int k=s.size();
	for(int i=0;i<k;i++){
		int t=s[i]-'0';
		if(t>=0&&t<=9){
			a[t]++;
		}
	}for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++){
			cout<<i;
		}
	}return 0;
}
