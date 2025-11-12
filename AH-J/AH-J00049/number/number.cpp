#include<bits/stdc++.h>
using namespace std;
string a;
int ans[1000005],s,i,j=0;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>a;
    s=a.size();
    for(i=0;i<s;i++){
        if(a[i]>='0'&&a[i]<='9'){
            ans[i]=a[i]-'0';
            j++;
        }
    }
    sort(ans,ans+s,cmp);
    for(i=0;i<j;i++){
        cout<<ans[i];
    }
    return 0;
}
