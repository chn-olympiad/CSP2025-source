#include<bits/stdc++.h>
using namespace std;
int cnt[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int maxn=0;
	for(int i=0;i<s.size();++i){
		if(s[i]>='0'&&s[i]<='9'){
			cnt[s[i]-'0']++;
			maxn=max(maxn,s[i]-'0');
		}
	}
	if(maxn==0)cout<<0<<endl;
	else{
		for(int i=9;i>=0;--i){
			for(int j=1;j<=cnt[i];++j){
				cout<<i;
			}
		}
	}
	return 0;
} 


