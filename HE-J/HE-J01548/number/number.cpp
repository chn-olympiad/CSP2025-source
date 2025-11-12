#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
	char v[s.size()]={'-1'};
    for(ll i=0;i<s.size();i++)
    {
        if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
            v[i]=s[i];
    }
    sort(v,v+s.size());
    for(ll i=s.size()-1;i>=0;i--)
    {
    	if(v[i]!='-1')
        	cout<<v[i];
    }
    return 0;
}
//5 5
//290es1q0 92100
