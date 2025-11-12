#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    getline(cin,s);
    int l=s.size();
    int c=0;
    for(int i=0;i<l;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[c++]=int(s[i])-48;
        }
    }

    sort(a,a+c,cmp);
    for(int i=0;i<c;i++){
        cout<<a[i];
    }
    return 0;
}
