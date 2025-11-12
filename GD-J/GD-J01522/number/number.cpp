#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6+5;
string s;
ll a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ll len = s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	//for(int i=0;i<=9;i++)cout<<a[i]<<" ";
	for(int i=9;i>=0;i--){
		if(a[i]){
			for(int j=1;j<=a[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}

