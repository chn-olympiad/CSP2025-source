#include<bits/stdc++.h>
using namespace std;
const int N=100020;
int a[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int j=0,sum;
    cin>>s;
    int lens=s.size();
    for(int i=0;i<lens;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
           a[j]=s[i]-'0';
           j++;
        }
    }
    for(int i=0;i<j;i++)
    {
       for(int x=i;x<j;x++)
        {
        if(a[x]>=a[i])
            {
            sum=a[x];
            a[x]=a[i];
            a[i]=sum;
            }
        }
    }

    for(int i=0;i<j;i++)
        cout<<a[i];
    return 0;
}
