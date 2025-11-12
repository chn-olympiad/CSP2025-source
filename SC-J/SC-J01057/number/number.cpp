#include<bits/stdc++.h>
#define int long long
using namespace std;
string w;
int a[10];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>w;
	for(int i=0;i<w.length();i++){
		if(w[i]>='0'&&w[i]<='9'){
			a[w[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++)cout<<i;
	}
	return 0;
}
