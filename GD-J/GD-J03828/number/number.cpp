#include<bits/stdc++.h>
using namespace std;
int cnt[15],tot;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<(int)(s.size());i++){
		if(s[i]>='0'&&s[i]<='9'){
			int x=(int)(s[i]-'0');
			cnt[x]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(cnt[i]--){
			cout<<i;
		}
	}
	return 0;
} 
