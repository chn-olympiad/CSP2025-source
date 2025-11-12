#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
#include<vector>
using namespace std;
bool cmp(const int &a,const int &b){
    return a>b;
}
int a[10];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    bool flag=false;
    cin>>s;
    //cout<<s;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i]&&s[i]<='9'){
            a[(int)(s[i]-'0')]++;
            if(s[i]!='0')flag=true;
        }
    }
    if(!flag)
    {
        cout<<0;
    }
    else{
        for(int i=9;i>=0;i--){
            for(int j=0;j<a[i];j++)cout<<i;
        }
    }
    return 0;
}
