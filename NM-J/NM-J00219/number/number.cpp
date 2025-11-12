#include<bits/stdc++.h>
using namespace std;
int num[0];
char a[10]={'0','1','2','3','4','5','6','7','8','9',};
int main()
{
	freopen("number.in","r",stdin); 
	freopen("number.out","w",stdout);
    int n=2e6;
    char s[n];
    cin>>s;
    for(int i=0;i<=10;i++)
    {
        if(s[i]>'9')
        	return 0;
        else
        	cout<<s[i];
    }
    return 0;
}

