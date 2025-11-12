#include<bits/stdc++.h>
using namespace std;
string s;
int x;
bool f=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	sort(s.begin(),s.end());
	if(s[s.size()-1]<'a'){
		for(int i=s.size()-1;i>=0;i--)
		{cout<<s[i];}
		return 0;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]<'0'||s[i]>'9'){
			x=i;
			break;
		}
		if(s[i]>='0'&&s[i]<='9'){
			f=1;
		}
	}	
	if(x==0&&f==1) x=s.size();
	for(int i=x-1;i>=0;i--) cout<<s[i];
	return 0;
}
