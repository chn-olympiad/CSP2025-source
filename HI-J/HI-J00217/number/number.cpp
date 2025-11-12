#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll a[30],l;
int main(){
	ios::sync_with_stdio(false);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]-'0'<0 || s[i]-'0'>9){
			//cout<<s[i]<<endl;
			continue;
		}
		a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
}

