#include<bits/stdc++.h>
#define ll long long
using namespace std;
string str; 
ll s=0;
ll f[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]>='0'&&str[i]<='9'){
			ll h=int(str[i]);
			f[h]++;
			s++;
		}
	}
	for(ll i=57;i>=48;i--){
		if(f[i]!=0){
			for(ll j=1;j<=f[i];j++){
				cout<<char(i);
			}
		}
	}
	return 0;
}

