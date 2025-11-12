#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s=0;
char a[1000005];
char t[10]={'0','1','2','3','4','5','6','7','8','9'};
ll num[1000005];
/*bool cmp(int x,int y)
{
    if(x>y) return x>y;
    else return x<y;
}*/
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<sizeof(a);i++)
    {
        if(a[i]-'0'>=0&&a[i]-'0'<=9)
            {num[s]=a[i]-'0';s++;
            }
    }
   /* for(int i=1;i<sizeof(num);i++)
    {
        if(num[i]>num[i-1])
        {
            int temp=num[i];
            num[i]=num[i-1];
            num[i-1]=temp;
        }
    }*/
    sort(num,num+s);
    for(int i=s-1;i>=0;i--)
        cout<<num[i];
    cout<<endl;
    /*cin>>a;
    for(int i=0;i<100000;i++) num[i]=a[i]-'0';
    sort(num,num+sizeof(a));
    for(int i=0;i<sizeof(a);i++) cout<<num[i];
    cout<<endl;*/
    return 0;
}
