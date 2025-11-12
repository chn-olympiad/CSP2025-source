#include<bits/stdc++.h>
using namespace std;
int s[1005]; 
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//ÊäÈë×Ö·û´®
	cin>>s[1005]; 
	sort(s,s+1005);
	for(int i=1005;i>=1;i--)
	{
		if(s[i]==0)
		{
			break;
		}
		else
		{
			cout<<s[i];
		}
	}
	return 0;
	//±£´æ£¬½â×¢ÊÍ 
 } 
