#include<bits/stdc++.h>
using namespace std;
int a[5000005];

bool cmp(int x,int y){
    return x>y;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    int t=0;
    for (int i=0;i<s.size();i++){
        if (s[i]>='0'&&s[i]<='9'){
            a[++t]=s[i]-'0';
        }
    }
    sort(a+1,a+t+1,cmp);
    for (int i=1;i<=t;i++){
        cout<<a[i];
    }
    return 0;
}
