//xjz0918 CSP-J2025RP++
//From GAN NAN SHI DA FU ZHONG
#include<bits/stdc++.h>
using namespace std;
string s;
int lens,a[1000010];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    lens=s.size();
    int j=0;
    for(int i=0;i<lens;i++)
    {
        if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
        {
            j++;
            a[j]=s[i]-'0';
        }
    }
    sort(a+1,a+j+1);
    for(int i=j;i>=1;i--)
    {
        cout<<a[i];
    }
    return 0;
}
