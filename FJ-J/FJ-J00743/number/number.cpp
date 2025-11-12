#include<bits/stdc++.h>
using namespace std;
int t[1000005],cnt;
string s;
bool flag=false;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9'){
			t[cnt++]=s[i]-'0';
			if(s[i]-'0'!=0)
				flag=true;
		}
	if(!flag){
		cout<<0<<endl;
		return 0;
	}
	sort(t,t+cnt);
	for(int i=cnt-1;i>=0;i--)
		cout<<t[i];
	return 0;
}
