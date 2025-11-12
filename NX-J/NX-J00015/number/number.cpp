#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int a[1000005]={0};
    string s;
    cin>>s;
    int len=0;
    int j=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            int sum=s[i]-'0';
            a[j]=sum;
            j++;len++;
        }
    }
    sort(a,a+len);
    for(int i=len-1;i>=0;i--)
    {
        cout<<a[i];
    }
    //fclose("number.in");
    //fclose("number.out");
    return 0;
}
