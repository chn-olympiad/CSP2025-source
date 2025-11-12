#include <iostream>
#include <bits/stdc++.h>
using namespace std;
char s[1010000];
int b[20];

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;

    int l=strlen(s);
    for(int i=0;i<=l-1;i++)
    {
        if(s[i]=='0')
        {
            b[0]++;
        }
        else
        {
            if(s[i]=='1')
            {
                b[1]++;
            }
            else
            {
                if(s[i]=='2')
                {
                    b[2]++;
                }
                else
                {
                    if(s[i]=='3')
                    {
                        b[3]++;
                    }
                    else
                    {
                        if(s[i]=='4')
                        {
                            b[4]++;
                        }
                        else
                        {
                            if(s[i]=='5')
                            {
                                b[5]++;
                            }
                            else
                            {
                                if(s[i]=='6')
                                {
                                    b[6]++;
                                }
                                else
                                {
                                    if(s[i]=='7')
                                    {
                                        b[7]++;
                                    }
                                    else
                                    {
                                        if(s[i]=='8')
                                        {
                                            b[8]++;
                                        }
                                        else
                                        {
                                            if(s[i]=='9')
                                            {
                                                b[9]++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for(int i=9;i>=0;i--)
    {
        while(b[i]!=0)
        {
            cout<<i;
            b[i]--;
        }
    }

    return 0;
}
