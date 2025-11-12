#include<bits/stdc++.h>
using namespace std;
char a[20]={'0','1','2','3','4','5','6','7','8','9'};
int n[20]={0,1,2,3,4,5,6,7,8,9};
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int t=1,d[100100];
    cin>>s;
    for(int i=0;i<=s.size()-1;i++)
    {
        for(int j=0;j<=9;j++)
        {
            if(s[i]==a[j])
            {
                d[t]=n[j];
                t++;
                break;
            }
        }
    }
    sort(d+1,d+t);
    for(int i=1;i<=t-1;i++)
    {
        cout<<d[t-i];
    }
    return 0;
}
