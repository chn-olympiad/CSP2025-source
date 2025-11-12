#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char a[N]={'$'};
int Size=0,b[N],k=0;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<N;i++)
        if(a[i]!='$') Size++;
    for(int i=0;i<Size;i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            b[k]=(int)(a[i]-48);
            k++;
        }
    }
    sort(b,b+k,cmp);
    for(int i=0;i<k;i++)
        cout<<b[i];
    cout<<endl;
    return 0;
}

