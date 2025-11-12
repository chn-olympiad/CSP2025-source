#include<bits/stdc++.h>
using namespace std;
char s[1000000];
int a[1000000],sum;
int main()
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>s;
int lens=strlen(s);

for(int i=0;i<lens;i++)
{

    if(s[i]>='0'&&s[i]<='9')
    {
        a[i]=s[i]-'0';
   sum++;
    }
}
for(int i=0;i<lens;i++)
{
    for(int j=0;j<lens-i;j++)
    {

        if(a[j]<a[j+1])
        {

            swap(a[j],a[j+1]);
        }
    }

}
for(int i=0;i<sum;i++)
{

    cout<<a[i];
}

return 0;
}
