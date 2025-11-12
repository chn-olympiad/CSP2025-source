#include<bits/stdc++.h>
using namespace std;
string s;
long long su[15];
bool flag=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	//cout<<s<<endl;
	for(int i=0;i<s.size();i++) if('0'<=s[i]&&s[i]<='9') su[s[i]-'0']++;
	for(int i=1;i<=9;i++)
		if(su[i]!=0){
			flag=1;
			break;
		}
	if(flag==0){
		putchar('0');
		return 0;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=su[i];j++){
			putchar(i+'0');
		}
	}
	return 0;
}
