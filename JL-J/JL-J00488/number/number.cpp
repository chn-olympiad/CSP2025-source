#include<bits/stdc++.h>
using namespace std;
bool cmp(char x,char y){
    return x>y;
}
char a[1000005];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,s1;
    int n,t=1;
    cin>>s;
    n=s.length();
    for(int i=0;i<n;i++)
    {
        if(s[i]>='1'&&s[i]<='9'){
            a[t]=s[i];
            t++;
        }
    }
    sort(a+1,a+n+1,cmp);
    for(int i=0;i<n;i++)
    {
        s1+=a[i];
    }
    cout<<s1<<endl;
    return 0;
}
