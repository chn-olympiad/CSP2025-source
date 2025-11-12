#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int length=a.length();
    short int number[length];
    for(int i=0; i<length; i++)
    {
        number[i]=-1;
    }
    int c=0;
    for(int i=0; i<length; i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            number[c]=a[i]-'0';
            c++;
        }
    }
    string answer="";
    int pos;
    int maxnumber;
    for(int i=0; i<c; i++)
    {
        pos=0;
        maxnumber=number[0];
        number[0]=-1;
        for(int j=1; j<c; j++)
        {
            if(number[j]!=-1)
            {
                if(maxnumber<number[j])
                {
                    number[pos]=maxnumber;
                    maxnumber=number[j];
                    number[j]=-1;
                    pos=j;
                }
            }
        }
        answer+=to_string(maxnumber);
    }
    cout<<answer;
    return 0;
}
