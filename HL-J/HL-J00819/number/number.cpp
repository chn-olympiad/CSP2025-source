#include <bits/stdc++.h>
using namespace std;

bool sort_rule(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int s_n_len = 0;
	string s;
	cin>>s;
	vector<int> n(s.length());
	int j=0;
	for(int i = 0;i<s.length();i++){
		if('0'<=s[i] && s[i]<='9'){
			s_n_len++;
			n[j] = s[i]-'0';
			j++;
		}
	}

	sort(n.begin(),n.end(),sort_rule);
	for(int i =0;i<s_n_len;i++){
		cout<<n[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}