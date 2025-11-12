#include<bits/stdc++.h>
using namespace std;
int sl[1939];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int yssl=s.size();
	for(int i=0;i<yssl;i++){
		if(s[i]>='0'&&s[i]<='9')sl[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=sl[i];j++)cout<<i;
	}
	return 0;
}
