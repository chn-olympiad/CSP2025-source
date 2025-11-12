#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char a[N];
bool cmp(char x,char y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    int d=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[d]=s[i];
            d++;
        }
    }
    sort(a,a+d,cmp);
    for(int i=0;i<d;i++){
        cout<<a[i];
    }
    return 0;
}
