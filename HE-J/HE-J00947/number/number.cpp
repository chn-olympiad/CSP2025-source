#include<bits/stdc++.h>
using namespace std;
int num=0;
int main()
{
   freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
    string s;
    cin>>s;
int a[1005];
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {

            a[num]=s[i]-'1'+1;

            num++;

        }

       }
    for(int i=0;i<num;i++)

{


        for(int j=1;j<num;j++)
        {

            if(a[j]>a[j-1])
            {

                int x=a[j];
                a[j]=a[j-1];
                a[j-1]=x;

            }
        }
}
        for(int i=0;i<num;i++)
        {

            cout<<a[i];
        }

    }



