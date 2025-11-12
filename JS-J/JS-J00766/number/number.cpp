#include <bits/stdc++.h>
using namespace std;
char a[1000005];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int sum=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            sum++;
            a[sum]=s[i];
        }
    }
    sort(a+1,a+sum+1);
    for(int i=sum;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
