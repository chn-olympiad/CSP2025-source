#include<iostream>
#include<string>
#include<algorithm>
using namespace std;



int a[1000050]={-1};
bool b[1000050];

bool cmp(int a,int b)
{
    return a>b;
}


int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int sum=0;
    for(int i=0;s[i];i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[i]=(int)(s[i]-'0');
            if(a[i]==0) sum++;
        }
    }
    sort(a,a+1000050,cmp);
    int i=0;

    while(a[i]>0)
    {
        cout<<a[i];
        i++;
    }
    for(int i=1;i<=sum;i++) cout<<0;
    return 0;
}
