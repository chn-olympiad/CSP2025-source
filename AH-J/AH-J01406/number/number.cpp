#include<bits/stdc++.h>
using namespace std;
int cot[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
		if(s[i]>='0'&&s[i]<='9') cot[s[i]-'0']++;
	for(int i=10;i>=0;i--)
		while(cot[i]>0){
			cout<<i;
			cot[i]--;
		}
	return 0;
}
