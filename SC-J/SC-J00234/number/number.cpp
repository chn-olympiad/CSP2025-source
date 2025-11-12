#include<bits/stdc++.h>
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
const ull N = 15;

std::string s;
int num[N];

signed main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
//	freopen("down/number/number4.in","r",stdin);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	std::cin>>s;
	for(ui i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			num[s[i]-'0']++;
		}
	}
	
	
	for(int i=9;i>=0;i--){
		for(int j=1;j<=num[i];j++)std::cout<<i;
	}
	return 0;
}