#include<bits/stdc++.h>
using namespace std;
string s,ans;
int i,j,l;
char ch1;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    l=s.size();
    for(i=0;i<l;i++)
    {
        ch1=s[i];
        if(ch1>='0'&&ch1<='9')
            ans=ans+ch1;
    }
    int l2=ans.size();//5323425847
    for(i=0;i<l2;i++)
    {
        for(j=i+1;j<l2;j++)
            if(ans[i]<=ans[j])
               swap(ans[i],ans[j]);
    }
    cout<<ans;
    return 0;
}
