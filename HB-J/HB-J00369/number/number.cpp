#include<bits/stdc++.h>

using namespace std;

char s;
int a[1005];

int main(void)
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int j=1;
    while(cin>>s)
    {
        cin>>s;
        if(s<='9'&&s>='0')
        {
            a[j]=s-'0';
            j++;
        }
    }

    sort(a+1,a+j-1);

    if(a[j-1]==0)
    {
        cout<<"0";
        return 0;
    }

    for(int i=j-1;i>=1;i--){
        cout<<a[i];
    }

    return 0;
}
