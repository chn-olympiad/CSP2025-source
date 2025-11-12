#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000002],k=0;
bool cmp(int c,int d){
    return c>d;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[k]=s[i]-48;
            k++;
        }
    }
    sort(a,a+k,cmp);
    for(int i=0;i<k;i++){
        cout<<a[i];
    }
    return 0;
}
