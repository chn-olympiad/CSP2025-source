#include<bits/stdc++.h>
using namespace std;
string a;
vector<int> s;
bool cmp(int q1,int q2){
    return q1>q2;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            int t=a[i]-'0';
            s.push_back(t);
        }
    }
    sort(s.begin(),s.end(),cmp);
    for(int q:s){
        cout<<q;
    }
    return 0;
}

