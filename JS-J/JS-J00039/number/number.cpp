#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int a[10];
    for(int i=0;i<=9;i++)
    a[i]=0;
    cin>>s;
    int len=s.size();
    for(int i=0;i<len;i++)
    {
        if(s[i]<='9'&&s[i]>='0')
        a[s[i]-'0']++;
        }
    for(int i=9;i>=0;i--){
        while(a[i]--){
            cout<<i;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
