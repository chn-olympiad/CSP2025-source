#include<bits/stdc++.h>
using namespace std;
const int N=110;
string s;
int l[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>s;
	int ls=s.size();
	for(int i=0;i<ls;i++){
		if(s[i]>='0'&&s[i]<='9'){
			l[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int o=1;o<=l[i];o++){
			cout<<i;
		}
	}
	return 0;
}