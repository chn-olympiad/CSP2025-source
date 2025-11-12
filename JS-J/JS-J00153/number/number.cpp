#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{

    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int c[1000005]={};
    cin>>s;
    int len=s.size();
    int hed=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            hed++;
            c[hed]=s[i]-'0';
        }
    }
    sort(c+1,c+hed+1,cmp);
    int ans=0;
    for(int i=1;i<hed;i++)
    {
        cout<<c[i];
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
