#include<bits/stdc++.h>
using namespace std;
string s1;
vector <int> a;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s1;
    for(int i=0;i<s1.size();i++){
        if(s1[i]>='0'&&s1[i]<='9'){
            a.push_back(s1[i]-48);
        }
    }
    int len=a.size();
    sort(a.begin(),a.end(),cmp);
    if(a[0]==0)cout<<0;
    else {
        for(int i=0;i<a.size();i++){
            cout<<a[i];
        }
    }
    return 0;
}
