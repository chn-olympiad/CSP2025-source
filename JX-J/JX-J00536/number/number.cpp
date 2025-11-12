#include<bits/stdc++.h>
using namespace std;

string s;
long long a[1000010],b[1000010],maxa=-1e9;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin >> s;
    for(int i=1;i<=s.size();i++)
    {
        if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
        {
            s[i]=a[i];
        }
        if(a[i]<a[i+1])
        {
            a[i+1]=b[i];
            a[i]=b[i+1];
        }
        else
        {
            a[i]=b[i];
            a[i+1]=b[i+1];
        }
    }
    for(int i=1;i<=s.size();i++)
    {
        maxa=max(maxa,b[i]);
    }
    cout << maxa;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
