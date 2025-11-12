#include<bits/stdc++.h>
using namespace std;
string s;
int num[1000005],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[++cnt]=int(s[i]-'0');
		}
	}
	sort(num+1,num+cnt+1,greater<int>());
	for(int i=1;i<=cnt;i++)
		cout<<num[i];
	
	return 0;
} 
