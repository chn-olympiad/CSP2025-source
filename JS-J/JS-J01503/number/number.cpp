#include<bits/stdc++.h>
using namespace std;
string s;
int hx[21];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int k=1;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            int tmp=s[i]-'0';
            hx[tmp]++;
        }
    }
    for(int j=9;j>=0;j--)
        for(int i=1;i<=hx[j];i++) cout<<j;
    fclose(stdin);
    fclose(stdout);

    return 0;
}
