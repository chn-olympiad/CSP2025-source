#include<bits/stdc++.h>
using namespace std;
string s;
int k;
int a[1000005];
bool cmp(int x,int y)
{
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    memset(a,-1,sizeof(a));
    int l=s.size();
    for(int i=0;i<l;i++)
    {
        if(s[i]-'0'>=0 && s[i]-'0'<=9)
        {
            a[i]=s[i]-'0';
            k++;
        }
    }
    sort(a,a+l,cmp);
    for(int i=0;i<l;i++)
    {
        if(a[i]!=-1) cout<<a[i];
    }
    return 0;
}
