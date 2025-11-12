#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N];
int in = 1;
bool cmp(int x,int y){
    return x > y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i] >= '0' && s[i] <= '9'){
            a[in] = (s[i] - '0');
            in++;
        }
    }
    sort(a+1,a+in,cmp);
    for(int i=1;i<in;i++){
        printf("%d",a[i]);
    }
    return 0;
}
