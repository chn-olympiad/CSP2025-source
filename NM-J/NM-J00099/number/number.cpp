#include<bits/stdc++.h>
using namespace std;
#define ll long long;
const int N=2e6+7;
string s;
int a[N]={-1};

bool cmp(int x,int y){
    return x>y;
}
int cnt=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[i]=s[i]-'0';
            cnt++;
        }
    }

    sort(a,a+s.size(),cmp);
    for(int i=0;i<cnt;i++){
        if(a[i]!=N){
            cout<<a[i];
        }
    }

    return 0;


}
