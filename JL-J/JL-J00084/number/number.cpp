#include<bits/stdc++.h>
using namespace std;
char s[10000000],n[1000000];
int main( ){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>s;
int ans=strlen(s);
for(int i=1;i<ans;i++)
{
    if(s[i]=='9' && s[i]>='0')
    {
      n[i]=s[i]-'0';
    }
}

for(int i=0;i<ans;i++)
{
    for(int j=0;j<ans-i;j++)
    {
        if(n[j],n[j+1])
        {
            swap(n[j],n[j+1]);
        }
    }
}

for(int i=0;i<ans;i++)
{
    cout<<n[i]<<endl;
}

return 0;
}

