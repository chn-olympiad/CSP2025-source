#include<bits/stdc++.h>
using namespace std;

const int N=10e6+5;
int a[N];

bool cmp(int x,int y){
    return x>y;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string s;
    cin>>s;

    int x=0;
    int len=s.length();
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[x]=int(s[i]-'0');
            x++;
        }
    }
    sort(a,a+x,cmp);
    for(int i=0;i<x;i++){
        cout<<a[i];
    }

    return 0;
}
