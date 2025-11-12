#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int num[N],temp=0;
bool cmp(int x,int y)
{
    if(x>y)
        return 1;
    return 0;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    for(int i=0;i<a.size();i++)
        if(a[i]>='0'&&a[i]<='9')
        {
            num[temp]=a[i]-'0';
            temp++;
        }
    sort(num,num+temp,cmp);
    for(int i=0;i<temp;i++)
        cout<<num[i];
    cout<<endl;
    return 0;
}
