#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a[s.length()+1],cnt=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            a[cnt]=s[i]-48;
            cnt++;
        }
    }
    sort(a,a+cnt);
    for(int i=cnt-1;i>=0;i--)
        cout<<a[i];
    return 0;
    fclose(stdin);
    fclose(stdout);
}
