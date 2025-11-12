#include<bits/stdc++.h>
using namespace std;

int a[1000010];
char s[1000010];
int len;

bool cmp(int a,int b) {
    return a>b;
}

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin>>s;
    int t=strlen(s);

    for(int i=0;i<t;i++) {
        if(s[i]>='0' && s[i]<='9') {
            len++;
            a[i]=s[i]-48;
        }
    }
    sort(a,a+t,cmp);
    for(int i=0;i<len;i++)
    {

        cout<<a[i];
    }
    return 0;
}
