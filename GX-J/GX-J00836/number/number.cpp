#include<bits/stdc++.h>
using namespace std;
int main()
{
ios::sync_with_stdio(false);
cin.tie(0);
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
long long s;
long long sum=0;
int e=0;
cin>>s;
 while (long(s))
{
    if(s[e]/2==1)
    {
        if (s>s[e-1])
        {
            e++;
            sum+=s[e]*10^e;
        }
        else
        {
            e++
            sum+=s[e]*10^(e-1);
        }
    }
    else if(s[e]/2==0)
    {
        if(s[e]==0)
        {
            sum=sum*10;
        }
        else
        {
            if(s[e]>s[e-1])
            {
                e++;
                sum+=s[e]*10^e;
            }
            else
            {
                e++;
                sum+=s[e]*10^(e-1);
            }
        }
    }
cout<<sum;
return 0;
}
