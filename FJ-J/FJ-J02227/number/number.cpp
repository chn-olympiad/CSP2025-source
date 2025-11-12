#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[10];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i] and s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(a[i]==0){
			continue;
		}else{
			for(int j=1;j<=a[i];j++){
				cout<<i;
			}
		}
	}
}