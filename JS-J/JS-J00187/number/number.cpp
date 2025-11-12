#include<bits/stdc++.h>
using namespace std;
string s;
bool c=0;
int k=1,a[10000001];
bool cmp(int q,int h){
    return q>h;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[k]=s[i]-'0';
            k++;
            if(s[i]!='0'){
                c=1;
            }
        }
    }
    if(c==0){
        cout<<0;
        return 0;
    }
    sort(a+1,a+k,cmp);
    for(int i=1;i<k;i++){
        cout<<a[i];
    }
    return 0;
}
