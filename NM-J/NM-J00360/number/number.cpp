#include<bits/stdc++.h>
using namespace std;
int a[100100];
int sum;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int i;
    cin>>s;
    for(i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9'){
            sum++;
            a[i]=s[i]-'0';
        }
    }
    sort(a,a+100100);
    reverse(a,a+100100);
    for(i=0;i<sum;i++){
        cout<<a[i];
    }
    return 0;
}
