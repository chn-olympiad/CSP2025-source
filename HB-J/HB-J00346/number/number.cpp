#include<bits/stdc++.h>
using namespace std;
string a,s=" ";
int t;
bool cmp(char x,char y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            s+=' ';
            s[t++]=a[i];
        }
    }
    sort(s.begin(),s.end(),cmp);
    s.erase(s.size()-1);
    cout<<s;
    return 0;
}
