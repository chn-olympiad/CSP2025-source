#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll b[1000005];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int cnt=0;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            cnt++;
            b[cnt]=a[i]-'0';
        }
    }
    sort(b+1,b+cnt+1,cmp);
    for(int i=1;i<=cnt;i++){
        cout<<b[i];
    }
    return 0;
}
