#include<bits/stdc++.h>
namespace zcy{
	using namespace std;
	int cnt[11]={};
	int main(){
		#ifndef debug
		freopen("number.in","r",stdin);
		freopen("number.out","w",stdout);
		#endif
		ios::sync_with_stdio(false);
		cin.tie(0);
		
		string s;
		cin>>s;
		
		for(int i=0;i<(int)s.size();i++){
			if(s[i]>='0'&&s[i]<='9'){
				cnt[s[i]-'0']++;
			}
		}
		
		for(int i=9;i>=0;i--){
			while(cnt[i]--)cout<<i;
		}
		cout<<endl;
		return 0;
	}
}
int main(){
	zcy::main();
	return 0;
}
