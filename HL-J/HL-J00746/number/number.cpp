#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
//   	ios::sync_with_stdio(0);
//   	cin.tie(0);cout.tie(0);
//    int a[1000005];
    int n=0;
    cin>>s;
    vector<int> a(s.size()+1);
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            a[++n]=s[i]-'0';
        }
    }
    sort(a.begin()+1,a.begin()+n+1,cmp);
    for(int i=1;i<=n;i++){
        cout<<a[i];
    }
}
