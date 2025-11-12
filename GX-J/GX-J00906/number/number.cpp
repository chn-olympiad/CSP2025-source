#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string str1;
    char c1;
    long long a,b,c,r,n,x=0,y;
    getline(cin,str1);
    long long temp[20]={0};
    for(int i=0;i<=str1.size();i++)
    {
        if(str1[i]>='0'&&str1[i]<='9')
        {
            if(str1[i]=='1')
            {
                x=1;
            }
            if(str1[i]=='2')
            {
                x=2;
            }
            if(str1[i]=='3')
            {
                x=3;
            }
            if(str1[i]=='4')
            {
                x=4;
            }
            if(str1[i]=='5')
            {
                x=5;
            }
            if(str1[i]=='6')
            {
                x=6;
            }
            if(str1[i]=='7')
            {
                x=7;
            }
            if(str1[i]=='8')
            {
                x=8;
            }
            if(str1[i]=='9')
            {
                x=9;
            }
            if(str1[i]=='0')
            {
                x=0;
            }
            temp[x]++;


        }
    }
    for(int i=11;i>=0;i--)
    {
        if(temp[i]!=0)
        {
            while(temp[i]!=0)
            {
                cout<<i;
                temp[i]-=1;
            }
        }

    }




    return 0;
}
