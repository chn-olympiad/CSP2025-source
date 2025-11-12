#include <bits/stdc++.h>
using namespace std;
string a;
//#define int long long
#define endl '\n'
signed main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	int k[10],n;
	for(int i=0;i<=9;i++){
		k[i]=0;
	}
	cin>>a;
	for(int i=0;a[i];i++){
		if(a[i]>='0'&&a[i]<='9'){
			n=int(a[i])-48;
			k[n]++;

		}

	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=k[i];j++){
			cout<<i;
		}
	}
	
	return 0;
}