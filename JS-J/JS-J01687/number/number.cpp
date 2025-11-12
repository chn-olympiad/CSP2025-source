#include<bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(int a,int b){
    return a > b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int i1 = 1;
    int n = s.length();
    for(int i = 0;i < n;i++){
        if(s[i] >= '0' && s[i] <= '9'){
            a[i1] = s[i] - '0';
            i1++;
        }
    }
    sort(a+1,a+i1,cmp);
    for(int i = 1;i < i1;i++){
        cout << a[i];
    }
}
