#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int cnt[1000005];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int x=1,a;
    cin>>s;
    a=s.size();
    for(int i=0;i<a;i++)
    {
	    if(s[i]=='0') 
	    {
			cnt[x]=0; 
			x+=1;
			continue;
		}
		if(s[i]=='1') 
	    {
			cnt[x]=1; 
			x+=1;
			continue;
		}
		if(s[i]=='2') 
	    {
			cnt[x]=2; 
			x+=1;
			continue;
		}
		if(s[i]=='3') 
	    {
			cnt[x]=3; 
			x+=1;
			continue;
		}
		if(s[i]=='4') 
	    {
			cnt[x]=4; 
			x+=1;
			continue;
		}
		if(s[i]=='5') 
	    {
			cnt[x]=5; 
			x+=1;
			continue;
		}
		if(s[i]=='6') 
	    {
			cnt[x]=6; 
			x+=1;
			continue;
		}
		if(s[i]=='7') 
	    {
			cnt[x]=7; 
			x+=1;
			continue;
		}
		if(s[i]=='8') 
	    {
			cnt[x]=8; 
			x+=1;
			continue;
		}
		if(s[i]=='9') 
	    {
			cnt[x]=9; 
			x+=1;
			continue;
		}
		
	}
	sort(cnt+1,cnt+x+1);
	for(int i=x;i>1;i--)
	{
		cout<<cnt[i];
	}
    return 0;
}
