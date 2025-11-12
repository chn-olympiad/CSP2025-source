#include<iostream>
#include<algorithm>
using namespace std;
int a[1000005];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int x=0;
    cin>>s;
    int len =s.size()-1;
    for(int i = 0;i<=len;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            x++;
            a[x]=s[i];
        }
    }
    sort(a+1,a+x+1,cmp);
    for(int i = 1;i<=x;i++)
    {

        cout<<a[i]-48;
    }
    return 0;
}
