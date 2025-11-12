#include<bits/stdc++.h>
using namespace std;
string s;
int venti,n=1,a[1000010];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    //cin
    cin>>s;
    venti=s.size();

    //choose maths
    for(int i=0;i<venti;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[n]=s[i]-'0';
            n++;
        }
    }

    //sort & cout
    sort(a+1,a+n);
    for(int i=n-1;i>0;i--)
    {
        cout<<a[i];
    }

    //I want to have one hundred,CCF.
    return 0;
}
