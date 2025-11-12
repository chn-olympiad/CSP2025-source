#include<bits/stdc++.h>
#define ll long long
using namespace std;
string str;
ll num[10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]>='0' && str[i]<='9') num[str[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		if(num[i]){
			while(num[i]){
				cout<<i;
				num[i]--;
			} 
		}
	}
	return 0;
}
