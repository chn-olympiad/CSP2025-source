#include <bits/stdc++.h>
using namespace std;
int cnt[11]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt[s[i]-'0']++;
		}
	}
	if(cnt[0]!=0){
		bool ok=1;
		for(int i=1;i<=9;i++){
			if(cnt[i]!=0){
				ok=0;
			}
		}
		if(ok){
			cout<<0<<endl;
			return 0;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=cnt[i];j++){
			cout<<i;
		}
	}
	cout<<endl;
	return 0;
}
