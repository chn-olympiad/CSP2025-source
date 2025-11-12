#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+12;
int lst[MAXN],index=0,num=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(lst,MAXN,MAXN);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9')
			lst[index]=s[i]-'0';
			index++;
	}
	sort(lst,lst+index);
	for(int i=index;i>=0;i--){
		if(lst[i]>MAXN) continue;
		cout<<lst[i];
	}
	return 0;
}