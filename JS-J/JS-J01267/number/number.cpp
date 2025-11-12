#include<bits/stdc++.h>
using namespace std;
#define ll long long
void IOS(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
}
int num[1000010],t=1;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    IOS();
    string a;cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0' && a[i]<='9'){
            num[t]=a[i]-'0';
            t++;      }
    }
    sort(num+1,num+t,cmp);
    for(int i=1;i<t;i++){
        cout<<num[i];
    }
    return 0;
}
