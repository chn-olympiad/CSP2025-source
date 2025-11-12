#include<bits/stdc++.h>
using namespace std;
string a;
int n;
int l[1000005];
struct str{
    int b;
};
bool cmp(str x,str y){
    if(x.b>y.b) return 1;
    return 0;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    str st[1000005];
    cin>>a;
    n=a.size();
    int sum=n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[j]=='9'&&l[j]==0)
            {
                st[j].b=9;
            }
            else if(a[j]=='8'&&l[j]==0)
            {
                st[j].b=8;
            }
            else if(a[j]=='7'&&l[j]==0)
            {
                st[j].b=7;
            }
            else if(a[j]=='6'&&l[j]==0)
            {
                st[j].b=6;
            }
            else if(a[j]=='5'&&l[j]==0)
            {
                st[j].b=5;
            }
            else if(a[j]=='4'&&l[j]==0)
            {
                st[j].b=4;
            }
            else if(a[j]=='3'&&l[j]==0)
            {
                st[j].b=3;
            }
            else if(a[j]=='2'&&l[j]==0)
            {
                st[j].b=2;
            }
            else if(a[j]=='1'&&l[j]==0)
            {
                st[j].b=1;
            }
            else if(a[j]=='0'&&l[j]==0)
            {
               st[j].b=0;
            }
            else
            {
                sum--;
            }
        }
    }
    sort(st+1,st+1+sum,cmp);
    for(int i=0;i<sum;i++)
    {
        cout<<st[i].b;
    }
    return 0;
}
