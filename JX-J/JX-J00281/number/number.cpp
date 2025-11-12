#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
string s;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int len=s.size();
    int cnt=1;
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9') a[cnt++]=s[i]-'0';
    }
    sort(a+1,a+1+cnt,cmp);
    int sum=0;
    for(int i=1;i<cnt;i++){
        sum+=a[i];
    }
    if(sum==0) cout<<0;
    else {
        for(int i=1;i<cnt;i++){
            cout<<a[i];
        }
    }
    return 0;
}
