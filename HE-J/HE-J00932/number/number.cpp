#include<bits/stdc++.h> 
using namespace std;
int ans[1000010];
int n=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
    cin>>s;
    for(int i=0;i<=s.size();i++)
    {
    	if(s[i]>='0'&&s[i]<='9')
    	{
    		if(s[i]=='1') ans[n]=1;
		    else if(s[i]=='2') ans[n]=2;
		    else if(s[i]=='3') ans[n]=3;
		    else if(s[i]=='4') ans[n]=4;
		    else if(s[i]=='5') ans[n]=5;
		    else if(s[i]=='6') ans[n]=6;
		    else if(s[i]=='7') ans[n]=7;
		    else if(s[i]=='8') ans[n]=8;
		    else if(s[i]=='9') ans[n]=9;
		    else if(s[i]=='0') ans[n]=0;
			n++;	
		}
	}
	sort(ans,ans+n);
    for(int i=n-1;i>=0;i--) 
	{
		cout<<ans[i];
	}
	return 0;
}
