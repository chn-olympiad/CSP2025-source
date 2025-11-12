#include<bits/stdc++.h>
using namespace std;
string s;
int n=0,a[100005];
int main()
{
    cin>>s;
    for(int i=0;i<s.size();i++){
	    if(48<=int(s[i])&&int(s[i])<58){
	    	a[n]=s[i]-48;
            n++;
	    }
    }
    sort(a,a+n+1);
    for(int i=n;i>=1;i--){
		cout<<a[i];
    }
    return 0;
}
