#include<bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(0));
    int n=10,q=10;
    cout<<n<<' '<<q<<"\n";
    for(int i=1;i<=n;i++)
    {
        int len=rand()%10+1;
        string s;
        for(int i=1;i<=len;i++) s+='a';
        s[rand()%len]='b';
        string t;
        for(int i=1;i<=len;i++) t+='a';
        t[rand()%len]='b';
        cout<<s<<" "<<t<<"\n";
    }
    for(int i=1;i<=q;i++)
    {
        int len=rand()%10+10;
        string s;
        for(int i=1;i<=len;i++) s+='a';
        s[rand()%len]='b';
        string t;
        for(int i=1;i<=len;i++) t+='a';
        t[rand()%len]='b';
        while(s==t) t[rand()%len]='b';
        cout<<s<<" "<<t<<"\n";
    }
}