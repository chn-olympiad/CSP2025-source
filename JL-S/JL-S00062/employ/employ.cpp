#include<bits/stdc++.h>
using namespace std;
int a[501];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,cnt1=0;
    string s;
    scanf("%d %d",&n,&m);
    cin>>s;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]==1){
            cnt1++;
        }
    }
    if(cnt1==n){
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                cout<<1;
                return 0;
            }
        }
        cout<<n;
        return 0;
    }
    return 0;
}
