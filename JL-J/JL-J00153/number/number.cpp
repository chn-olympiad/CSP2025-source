#include<bits/stdc++.h>
using namespace std;
int a[1000905];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int k=1;
    cin>>s;
    for(int i=0;i<=s.size()-1;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[k]=s[i]-'0';
            k++;
        }
    }
    sort(a+1,a+k+1,cmp);//
    for(int i=1;i<=k-1;i++)
    {
        cout<<a[i];
    }
    return 0;

}
