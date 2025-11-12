#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string inin;
    vector<int>num;
    cin>>inin;
    int lin=inin.size();
    for(int i=0;i<lin;i++){
        if(inin[i]>='0'&&inin[i]<='9'){
            num.push_back(inin[i]-'0');
        }
    }
    sort(num.begin(),num.end(),cmp);
    for(int i=0;i<num.size();i++){
        cout<<num[i];
    }
    cout<<endl;
    return 0;
}
