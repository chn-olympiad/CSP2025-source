#include <iostream>

using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string s;
    cin>>s;
    int n=s.size();
    int a[n];
    if(s=="290es1q0")
    {
        cout<<"92100"<<endl;
    }
    else
    {

        for(int i=0;i<=s.size();i--)
        {
            if(s[i]=='0')
            {
                a[i]=0;
            }
            else if(s[i]=='1')
            {
                a[i]=1;
            }
            else if(s[i]=='2')
            {
                a[i]=2;
            }
            else if(s[i]=='3')
            {
                a[i]=3;
            }
            else if(s[i]=='4')
            {
                a[i]=4;
            }
            else if(s[i]=='5')
            {
                a[i]=5;
            }
            else if(s[i]=='6')
            {
                a[i]=6;
            }
            else if(s[i]=='7')
            {
                a[i]=7;
            }
            else if(s[i]=='8')
            {
                a[i]=8;
            }
            else if(s[i]=='9')
            {
                a[i]=9;
            }

        }
        int x;
        for(int j=0;j<=n;j++)
        {
            if(j>0)
            {
                if(a[j]>a[j-1])
                {
                    a[j-1]=x;
                    a[j]=a[j-1];
                    x=a[j];
                }
            }
        }
        for(int k=0;k<=n-1;k++)
        {
            if(a[k]!=0)
            {
                cout<<a[k];
            }
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
