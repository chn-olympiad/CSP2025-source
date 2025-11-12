#include<bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);

    string s;
//    scanf("%s",&s);
    cin>>s;
    int l=s.size();
//    int t=0;
    for(int i=0;i<l;++i)
    {
    	if(s[i]>='0'&&s[i]<='9')
    	{
    		int t=s[i]-'0';
    		a[t]+=1;
//			++t;
		}
	}
//	for(int i=0;i<=9;i++)
//	{
//		cout<<a[i]<<" ";
//	}

//	string ans="";
	for(int i=9;i>=0;i--)
	{
		if(a[i]>=1)
        {
            for(int j=1;j<=a[i];j++)
            {
            	printf("%d",i);
			}
        }
	}
    return 0;
}
