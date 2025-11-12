#include<bits/stdc++.h>
using namespace std;
long long cnt[15],ans[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt[s[i]-'0']++;
		}
	}
	long long t=0;
	for(int i=9;i>=0;i--){
		while(cnt[i]--){
			ans[t++]=i;
		}
	}
	for(long long i=0;i<t;i++){
		cout<<ans[i];
	}
	cout<<"\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
