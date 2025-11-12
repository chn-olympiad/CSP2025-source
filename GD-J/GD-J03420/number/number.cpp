#include<bits/stdc++.h>
using namespace std;
int len;
int cnt[10];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++)
		if('0'<=s[i]&&s[i]<='9')
			cnt[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		while(cnt[i]--) cout<<char(i+'0');
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
