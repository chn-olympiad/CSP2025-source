#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	string s;
	int a[20]={};
	cin>>s;
	for(int i=0;i<1000000091;i++)
    {
        //cout<<i<<s[i]<<endl;
        //cout<<'!'<<(s[i]>='A'&&s[i]<='Z')<<(s[i]>='a'&&s[i]<='z')<<(s[i]>='0'&&s[i]<='9')<<endl;
        if( !((s[i]>='A'&&s[i]<='Z') || (s[i]>='a'&&s[i]<='z') || (s[i]>='0'&&s[i]<='9')))
        {
            break;

        }
        if(s[i]>='0'&&s[i]<='9')
        {
            a[int(s[i])-48]++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        for(int j = a[i];j>0;j--)
        {
            cout<<i;
        }
    }

	return 0;
}
