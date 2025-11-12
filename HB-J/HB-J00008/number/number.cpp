#include<bits/stdc++.h>
using namespace std;
int number1[500]={0};

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a,ans="";
    char c='0',d='1'.e='2',f='3',g='4',h='5',k='6',l='7',m='8',n='9'
    cin>>a;
    int b=0,maxn=0;
    b=a.size();
    for(int i=0;i<500;i++)
    {
        number1[i]=15;
    }
    for (int i=1;i<=b;i++)
    {
        if(a[i-1]=='1')
        {
            number1[1]=number1[1]++;
        }
        else if(a[i-1]=='2')
        {
            number1[2]=number1[2]++;
        }
        else if(a[i-1]=='3')
        {
            number1[3]=number1[3]++;
        }
        else if(a[i-1]=='4')
        {
            number1[4]=number1[4]++;
        }
        else if(a[i-1]=='5')
        {
            number1[5]=number1[5]++;
        }
        else if(a[i-1]=='6')
        {
            number1[6]=number1[6]++;
        }
        else if(a[i-1]=='7')
        {
            number1[7]=number1[7]++;
        }
        else if(a[i-1]=='8')
        {
            number1[8]=number1[8]++;
        }
        else if(a[i-1]=='9')
        {
            number1[9]=number1[9]++;
        }
        else if(a[i-1]=='0')
        {
            number1[0]=number1[0]++;
        }
    }
    for(int i=12;i>=1;i--)
    {
       maxn=number1[i]+maxn;
    }

    for(int i=12;i>=1;i--)
    {
       if(i==9)
        {
            ans=asn+n*number1[9];
        }
        else if(i==8)
        {
            ans=asn+m*number1[8];
        }
        else if(i==7)
        {
            ans=asn+l*number1[7];
        }
        else if(i==6)
        {
            ans=asn+k*number1[6];
        }
        else if(i==5)
        {
            ans=asn+h*number1[5];
        }
        else if(i==4)
        {
            ans=asn+g*number1[4];
        }
        else if(i==3)
        {
            ans=asn+f*number1[3];
        }
        else if(i==2)
        {
            ans=asn+e*number1[2];
        }
        else if(i==1)
        {
            ans=asn+d*number1[1];
        }
        else if(i==0)
        {
            ans=asn+c*number1[0];
        }
    }
    cout<<ans;
    return 0;
}
