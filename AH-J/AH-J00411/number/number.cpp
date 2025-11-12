#include<bits/stdc++.h>
using namespace std;
int nu[10];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;

    for(int i=0;i<s.size();i++)
    {
        nu[s[i]-'0']++;
    }

    for(int i=9;i>=0;i--){

        while(nu[i]!=0){
            cout<<i;
            nu[i]--;
        }
    }
    return 0;
}
