#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
    return x>y;
}
int aa[1000105];

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int cnt=0;
    string s;
    cin>>s;
    int n=s.length();
     for(int i=0;i<n;i++)
        if(s[i]>='0'&&s[i]<='9') {++cnt;aa[cnt]=s[i]-'0';}
    sort(aa+1,aa+cnt+1,cmp);
    if(aa[1]==0) {cout<<0;fclose(stdin);fclose(stdout);return 0;}
    for(int i=1;i<=cnt;i++)
    {
        cout<<aa[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
