#include<bits/stdc++.h>
using namespace std;
int a[1000010]={};
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.ans","w",stdout);
    string s;
    cin>>s;
    size_t n=s.size();
    int ans=0;
    for(int i=0; i<n; ++i)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            ans++;
            a[ans]=s[i]-'0';
        }
    }
    sort(a+1,a+1+ans);
    int k=0;
    for(int i=ans; i>0; --i)
    {
        k=k*10+a[i];
    }
    cout<<k;
    fclose(stdin);
    fclose(stdout);
}
