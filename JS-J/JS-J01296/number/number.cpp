#include<bits/stdc++.h>
using namespace std;
string s;
int cnt;
vector<int> v;
int a[1000005];
bool cmp(int a , int b){
    return a > b;
}
string ans;
int main(){
    freopen("number.in" , "r" , stdin);
    freopen("number.out" , "w" , stdout);
    cin >> s;
    for(int i = 0;i < s.size();i ++){
        if(s[i] >= '0' and s[i] <= '9'){
            v.push_back(s[i]-'0');
        }
    }
    for(int i = 0;i < v.size();i ++){
        a[i+1] = v[i];
    }
    sort(a+1 , a+v.size()+1 , cmp);
    for(int i = 1;i <= v.size();i ++){
        ans += a[i]+'0';
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
