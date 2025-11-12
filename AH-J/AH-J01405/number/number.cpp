#include<bits/stdc++.h>
using namespace std;
int a[10]={0},cnt=0;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
			a[(s[i]-'0')]++,cnt++;
	}


    for(int j=9;j>=0;j--)
    {
        while(a[j]>0)
        {
            printf("%d",j);
            a[j]--;

        }
    }

    return 0;
}
