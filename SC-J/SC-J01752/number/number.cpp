#include<bits/stdc++.h>
using namespace std;
string s;
char ch[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			cnt++;
			ch[cnt]=s[i];
		}
	}
	sort(ch+1,ch+cnt+1);
	for(int i=cnt;i>=1;i--)cout<<ch[i];
	return 0;
}
