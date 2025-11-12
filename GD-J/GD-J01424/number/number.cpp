#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a[s.size()+10],js=0;
    
    for(int i=0;i<s.size();i++){
    	if(s[i]-'0'<10 && s[i]-'0'>=0)a[js++]=s[i]-'0';
	}
	sort(a,a+js);
	for(int i=js-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
 } 
