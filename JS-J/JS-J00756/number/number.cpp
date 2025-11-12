#include<bits/stdc++.h>
using namespace std;
const int N =1e6+5;
int a[N],k;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string st;
    cin>>st;
    for(int i=0;i<st.length();i++){
        if(st[i]>='0'&&st[i]<='9'){
            a[++k]=st[i]-'0';
        }
    }
    sort(a+1,a+1+k,cmp);
    if(a[1]==0){
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<=k;i++){
        cout<<a[i];
    }
    cout<<endl;
    return 0;
}
