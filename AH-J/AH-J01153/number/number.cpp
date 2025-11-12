#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int n=a.size();
    int b_using=0;
    int b[1000000]={};
    for(int i=0;i<n;i++)
    {
        if(a[i]>='0' && a[i]<='9')
        {
            b[b_using]=a[i]-'0';
            b_using++;
        }
    }
    sort(b,b+b_using,cmp);
    for(int i=0;i<b_using;i++)
        cout<<b[i];
        return 0;
}
