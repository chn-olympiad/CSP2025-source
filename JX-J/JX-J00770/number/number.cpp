#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000006];
int cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++cnt]=s[i];
		}
	}
	sort(a+1,a+cnt+1,greater<int>());
	for(int i=1;i<=cnt;i++)cout<<a[i];
	return 0;
}
