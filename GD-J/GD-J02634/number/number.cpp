#include<bits/stdc++.h>
#define int long long
using namespace std;

string s;
int num[11];
bool flag=1;

signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if('0'<=s[i]&&s[i]<='9'){
			num[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(i==0&&flag){
			printf("0");
			break;
		}
		for(int j=1;j<=num[i];j++){
			printf("%lld",i);
			if(i!=0)flag=0;
		}
	}
	return 0;
}
