#include <bits/stdc++.h>
using namespace std;
int s[100][100];
int m[100];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n=0,a=0,b=0,c=0,sum=0;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>s[i][0]>>s[i][1]>>s[i][2];
        }
        for(int i=0;i<t;i++)
        {
            if(a<n/2 && s[i][0]>s[i][1] && s[i][0]>s[i][2])
            {
                a++;
                sum+=s[i][0];
            }
            else if(b<n/2 && s[i][1]>s[i][0] && s[i][1]>s[i][2])
            {
                b++;
                sum+=s[i][1];
            }
            else if(c<n/2 && s[i][2]>s[i][1] && s[i][2]>s[i][0])
            {
                c++;
                sum+=s[i][2];
            }
            else if(a==n/2)
            {
                if(s[i][2]>s[i][1])
                {
                    sum+=s[i][2];
                    c++;
                }
                else
                {
                    sum+=s[i][1];
                    b++;
                }
            }
            else if(b==n/2)
            {
                if(s[i][0]>s[i][2])
                {
                    sum+=s[i][0];
                    a++;
                }
                else
                {
                    sum+=s[i][2];
                    c++;
                }
            }
            else if(c==n/2)
            {
                if(s[i][0]>s[i][1])
                {
                    sum+=s[i][0];
                    a++;
                }
                else
                {
                    sum+=s[i][1];
                    b++;
                }
            }
            m[i]=sum;
        }
    }
    for(int i=0;i<t;i++)
    {
        cout<<m[i]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
