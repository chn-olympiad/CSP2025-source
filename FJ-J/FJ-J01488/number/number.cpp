#include <bits/stdc++.h>
using namespace std;
int cnt;
string s;
short num[1000005];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]<='9' && s[i]>='0'){
			num[cnt]=(s[i]-'0');
			cnt++;
		}
	}
	sort(num,num+cnt);
	for(int i=cnt-1;i>=0;i--) cout<<num[i];
	return 0;
}
