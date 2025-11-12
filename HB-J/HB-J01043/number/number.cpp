#include<bits/stdc++.h>
using namespace std;

int a[1000005],j=0;
string s;

bool cmp(int a,int b){
    return a>b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
        if(s[i]<='9' && s[i]>='0'){
            a[j]=s[i]-'0';
            j++;
        }
    sort(a+0,a+j,cmp);
    if(a[0]!=0)
        for(int i=0;i<j;i++)
            cout<<a[i];
    else cout<<0;
    cout << endl;
    return 0;
}