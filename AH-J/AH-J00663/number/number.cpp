#include<bits/stdc++.h>
using namespace std;
int i=0,n,l,j,s[1000001];
char a;
string st;
int cmp(int x,int y)
{
    return x>y?x:y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    while(cin>>a)
    {
        if(a>='0'&&a<='9')
        {
            i++;
            s[i]=a-'0';
            for(j=i;j>1;j--)
                if(s[j]>s[j-1])
                    swap(s[j],s[j-1]);
        }
    }
    for(j=1;j<=i;j++)cout<<s[j];
    return 0;
}
//#Shang4Shan3Ruo6Shui4
