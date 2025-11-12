#include <bits/stdc++.h>
using namespace std;

const int kac=1000010;
int s[kac]={};
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a;
    cin >> a;
    int txt=0;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            s[i]=a[i]-'0';
            txt++;
        }else{
        continue;
        }
    }
    sort(s,s+txt,cmp);
    long long m=0;
    for(int i=0;i<txt;i++){
            cout << s[i];
    }
    return 0;
}
