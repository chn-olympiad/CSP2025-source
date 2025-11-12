#include<bits/stdc++.h>
using namespace std;
#define int long long
int v[30];
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0; i<s.size(); i++){
		if(s[i]>='0'&&s[i]<='9') v[s[i]-'0']++;
    }
    for(int i=29; i>=0; i--){
		if(v[i]>=1){
			for(int j=1; j<=v[i]; j++){cout<<i;}
		}
	}
	return 0;
}
