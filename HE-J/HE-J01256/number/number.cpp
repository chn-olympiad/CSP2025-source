#include <bits/stdc++.h>
using namespace std;
vector<long long> q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(long long i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			q.push_back(s[i]-'0');
		}
	}
	sort(q.begin(),q.end());
	string ans;
	for(long long i=0;i<q.size();i++){
		ans.push_back(q[i]+'0');
	}
	int pos=ans.length()-1;
	while(pos>0){
		if(ans[pos]=='0'){
			pos--;
		}
		else{
			break;
		}
	}
	string tans;
	for(int i=pos;i>=0;i--){
		tans.push_back(ans[i]);
	}
	cout<<tans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
