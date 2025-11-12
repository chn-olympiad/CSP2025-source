#include<bits/stdc++.h>
using namespace std;
struct A{
    int n;
};
A a[1000005];
bool comp(A x,A y)
{
    if(x.n<=y.n)return 0;
    return 1;
}
int main()

{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int b=1,c=0;
    cin>>s;

    for(int i=0;i<s.size();i++)

    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[b].n=s[i]-('0'-0);
            b++;c++;
        }
    }
    sort (a+1,a+c+1,comp);


//   for(int i=1;i<=c-1;i++)
//   {
//       for(int j=1;j<=c-i;j++)
//       {
//           if(a[j]<a[j+1])
//           {
//               swap(a[j],a[j+1]);
//           }
//       }
//   }
    for(int i=1;i<=c;i++)
    {
        cout<<a[i].n;
    }
    return 0;
}
