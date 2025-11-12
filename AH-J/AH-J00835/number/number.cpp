#include<bits/stdc++.h>
using namespace std;
char a[10000005];
long long int b[10000005],c=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin.getline(a,10000005);
    for(long long int i=0;i<strlen(a);i++)
    {
		if(a[i]>='0'&&a[i]<='9')
        {
            b[c]=(a[i]-'0');
            c++;
        }
	}
	sort(b,b+c);
	for(long long int i=c-1;i>=0;i--)printf("%lld",b[i]);
    return 0;
}
