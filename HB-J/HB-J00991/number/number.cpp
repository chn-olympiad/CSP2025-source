#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000001];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int len=s.length();
    int k=0;
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[k]=s[i]-'0';
            k++;
        }
    }
    sort(a,a+len,cmp);
    for(int i=0;i<k;i++){
        cout<<a[i];
    }
    cout<<endl;
    return 0;
}
