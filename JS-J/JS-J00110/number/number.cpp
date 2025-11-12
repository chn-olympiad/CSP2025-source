#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000000],cnt=1;
bool cmp(int a,int b){
    return b<a;
}
int main(){
    std::ios::sync_with_stdio(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char c;
    while(cin>>c){
        if(c>='0' && c<='9'){
            a[cnt]=c-'0';
            cnt++;
        }
    }
    sort(a+1,a+cnt+1,cmp);
    for(int i=1;i<cnt;i++){
        cout<<a[i];
    }
    return 0;
}
