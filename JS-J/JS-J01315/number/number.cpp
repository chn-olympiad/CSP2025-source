#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
const int N=1e6+10;
string s;
int a[N]={0};
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int l=s.size(),la=1;
    for(int i=0;i<l;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[la]=int(s[i]-'0');
            la++;
        }
    }
    sort(a+1,a+la,cmp);
    if(a[1]==0)cout<<0;
    else{
        for(int i=1;i<la;i++){
            cout<<a[i];
        }
    }
    return 0;
}
