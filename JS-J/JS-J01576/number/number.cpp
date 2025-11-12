#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int a[110];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int t=s.size();
	for(int i=0;i<t;i++){
		if( (int)s[i]>=48&&(int)s[i]<=59 ){
			a[ (int)s[i]-48 ]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
}
