#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int  a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)	
	{
		if(s[i]<='9'&&s[i]>='0'){
			a[i]=s[i]-'0';
	 }
		if(s[i]<='z'&&s[i]>='a'){
			a[i]=s[i]-s[i];
		}
			
	}
	sort(a,a+s.size());	
	for(int i=s.size()-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
} 
