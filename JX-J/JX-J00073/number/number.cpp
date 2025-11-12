#include<bits/stdc++.h>
using namespace std;
int lnum=-1;
int a[1000050];
string n;
bool cmptt(int x,int y)
{
    return x>=y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>n;
    int l=n.size();
    for (int i=0;i<=l;i++)
    {
        if (n[i]>='0'&&n[i]<='9')
        {
            lnum=lnum+1;
            a[lnum]=n[i]-'0';
        }
    }
    sort(a,a+lnum+1,cmptt);
    for (int i=0;i<=lnum;i++)
        printf("%d",a[i]);
    printf("\n");
    return 0;
}
