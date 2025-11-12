#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t[100005];
	string s;
	cin >> s;
	int cnt=0;
	for(int i = 0; i < s.size(); i++){
		if(s[i]<='9' && s[i]>='0'){
		t[++cnt]=s[i]-'0';	
		}
	}
    sort(t+1,t+1+cnt);
	for(int i = cnt; i>= 1; i--){
		cout << t[i];
	}
	return 0;
}
