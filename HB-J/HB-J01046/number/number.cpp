#include<bits/stdc++.h>
using namespace std;
string a;
struct node
{
    int a;
};
 node ca[100000];
int b;
bool d(node m,node n)
{
    return m.a > n.a;
}
int main()
{   
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    b = a.size();
    int k = 0;
    for (int i = 0; i < b; i++)
    {
        if(a[i]=='9' or a[i]=='8' or a[i]=='7' or a[i]=='6' or a[i]=='5' or a[i]=='4' or a[i]=='3' or a[i]=='2' or a[i]=='1' or a[i]=='0')
        {
            ca[k].a = a[i] - '0';
            k++;
        }
    }
    int l = 1;
    while(l != 0)
    {
        l = 0;
        for (int i = 0; i < k-1; i++)
        {
        if(ca[i].a < ca[i+1].a)
        {
            l = 1;
            int o = ca[i].a;
            ca[i].a = ca[i+1].a;
            ca[i+1].a = o;
        }
    }
    }
    
  
    
    for (size_t i = 0; i < k; i++)
    {
        cout<<ca[i].a;
    }
    return 0;
}
