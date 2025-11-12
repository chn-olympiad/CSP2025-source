#include<bits/stdc++.h>
using namespace std;
long long a[105];
int main()
{

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int flag=0;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' and s[i]<='9'){
            if(s[i]!='0'){
                flag=1;
            }
            a[s[i]-'0']++;
        }
    }
    if(flag==0){
        cout<<0;
        return 0;
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=a[i];j++){
            cout<<i;
        }
    }
    return 0;
}
