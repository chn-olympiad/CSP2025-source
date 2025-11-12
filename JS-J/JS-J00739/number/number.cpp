#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> a;
    string s;
    cin>>s;
    int len=s.size();
    int n=0;
    for(int i=0;i<len;i++){
        if('0'<=s[i] && s[i]<='9'){
            int x=s[i]-'0';
            a.push_back(x);
            n++;
        }
    }
    sort(a.begin(),a.end());
    for(int i=n-1;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}
