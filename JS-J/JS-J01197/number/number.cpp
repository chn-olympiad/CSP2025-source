#include <bits/stdc++.h>
using namespace std;
string a;
int ans[1000005];

bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>a;
    int idx=0;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            idx++;
            ans[idx]=a[i]-'0';
        }
    }
    sort(ans+1,ans+idx+1,cmp);
    for(int i=1;i<=idx;i++)cout<<ans[i];
    return 0;
}
