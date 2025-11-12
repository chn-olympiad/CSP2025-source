#include<bits/stdc++.h>
#define int long long

using namespace std;
string str;
int n,c,b[1000001];
int cmp(int a,int b){
    return a>b;
}
queue<int>a;
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>str;

    n=str.length();
    for(int i=0;i<n;i++){
        if(str[i]>='0' && str[i]<='9'){
            a.push(str[i]-'0');
            c++;
            }
    }
    for(int i=0;i<c;i++){
        b[i]=a.front();
        a.pop();
    }
    sort(b,b+c,cmp);


    for(int i=0;i<c;i++){
        cout<<b[i];
    }
    return 0;
}
