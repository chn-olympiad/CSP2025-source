#include<bits/stdc++.h>
using namespace std;

string s;
char a[1000010];
int n=0;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin>>s;
    for(int i=0;i<s.size();i++)
    {

        if(s[i]>='0'&&s[i]<='9')
            a[n]=s[i];n++;
    }
    sort(a,a+n+1,cmp);
    for(int i=0;i<n;i++)
        cout<<a[i];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
