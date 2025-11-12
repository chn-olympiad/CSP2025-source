#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n,cnt=0;
    char y[100010],maxz='0',maxj;
    string s;
    cin>>s;
    n=s.length();
    for(int i = 0;i < n;i++)
    {
        if((s[i]<'9'&&s[i]>'0')||s[i]=='0'||s[i]=='9'){
            cnt++;
            y[cnt]=s[i];
        }
    }
    for(int i = 1;i <= cnt; i++)
    {
        for(int j = i; j <= cnt;j++){
            if(y[j]>maxz){
                maxz=y[j];
                maxj=j;
            }
        }
        char m;
        m=y[maxj];
        y[maxj]=y[i];
        y[i]=m;
        maxz='0';
    }
    for(int i = 1;i <= cnt; i++) cout << y[i];
    return 0;
}
