#include<bits/stdc++.h>
using namespace std;
int const N=1e6+10;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;cin>>s;
    int a[N]={},m=0;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]<='9'&&s[i]>='0'){
            a[m]=s[i]-'0';
            m++;
        }
    }
    sort(a,a+m,cmp);
    for(int i=0;i<m;i++){
        cout<<a[i];
    }
    return 0;
}
