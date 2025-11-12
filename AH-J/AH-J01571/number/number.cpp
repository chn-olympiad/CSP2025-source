#include<bits/stdc++.h>
using namespace std;
int a[1005],ans,cnt;
bool b[1005];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int k=1;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0')
        {
            a[k]=s[i]-'0';
            k++;
        }
    }
    for(int j=1;j<k;j++)
    {
        ans=-1;
        for(int l=1;l<k;l++)
        {
            if(b[l]==false)
            {
                if(a[l]>ans)
                {
                    ans=a[l];
                    cnt=l;
                }
            }
        }
        printf("%d",ans);
        b[cnt]=true;
    }
    return 0;
}
