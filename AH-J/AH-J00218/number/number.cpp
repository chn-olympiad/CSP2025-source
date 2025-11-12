#include<bits/stdc++.h>
using namespace std;
int a[100000005];
bool cmp(int c,int b){
    if(c!=b){
        return c>b;
    }
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string s;
    int minn=1e9;
    cin>>s;
    int s1=s.size();
    for(int i=0;i<s1;i++){
        a[i]=(s[i]-'0')%10;
        if(a[i]<minn){
            minn=a[i];
        }
    }
    sort(a+1,a+1+s1,cmp);
    for(int i=1;i<=s1;i++){
        if(i==s1){
            cout<<minn;
            break;
        }
        cout<<a[i];
    }
    return 0;
}
