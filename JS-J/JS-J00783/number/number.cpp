#include<bits/stdc++.h>
using namespace std;
int a[1000010];
void qs(int l,int r,int a[])
{
    int temp=a[l],i=l,j=r;
    if(i>=j)return;
    while(i<j)
    {
        while(a[j]>=temp)
        {
            j--;
            if(i==j)break;
        }
        a[i]=a[j];
            if(i==j)break;
        while(a[i]<=temp)
        {

            i++;
            if(i==j)break;
        }
        a[j]=a[i];
    }
    a[i]=temp;
    qs(l,i-1,a);
    qs(i+1,r,a);
    return;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
   cin>>s;
   int i,j=0,a[100010];
   int len=s.size();
    for(i=0;i<len;i++)
   {
       if(s[i]<='9'&&s[i]>='0')
      a[++j]=s[i]-'0';
    }
    qs(1,j,a);
    for(i=j;i>=1;i--)
        cout<<a[i];
    return 0;
}
