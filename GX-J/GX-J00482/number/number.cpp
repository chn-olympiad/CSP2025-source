#include <bits/stdc++.h>
using namespace std;
int num[1000005];
int main()
{

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    long long int ls=s.size(),j=0;
    for(int i=0;i<ls;i++){
        if(s[i]>='0'&&s[i]<='9'){
            num[j]=s[i]-'0';
            j++;
        }
    }
    sort(num,num+j);
    for(int i=j-1;i>=0;i--){
        cout<<num[i];
    }
    return 0;
}
