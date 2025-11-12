#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int k,a[N];
int main(){
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	auto it=s.size();
	for(int i=0;i<(int)it;i++){
		if((int)s[i]>=48&&(int)s[i]<=57){
			a[++k]=(int)s[i]-48;
		}
	}
	sort(a+1,a+k+1);
	for(int i=k;i>=1;i--){
		cout<<a[i];
	}
	return 0;
} 