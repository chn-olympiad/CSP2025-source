#include<bits/stdc++.h>
using namespace std;
int p(int a,int b){
    return a>b;
}
int cut=0;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    int len=s.size();
    int a[1000001]={};
    for(int i=0;i<len;i++){
        if(s[i]<='9'&&s[i]>='0'){
            cut++;
            a[i]=s[i]-'0';
        }
    }
    sort(a,a+len+1,p);
    for(int i=0;i<cut;i++){
        cout<<a[i];
    }
    return 0;
}
