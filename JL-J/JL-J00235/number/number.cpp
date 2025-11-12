#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a[s.size()+5];
    int j=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[j]=s[i]-48;
            j++;
        }
    }
    sort(a,a+j,cmp);
    for(int i=0;i<j;i++){
        cout<<a[i];
    }
    return 0;
}
