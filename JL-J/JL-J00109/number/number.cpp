#include <bits/stdc++.h>
using namespace std;
const int N=1000100;
char a[N];
long long b[N];
long long ans=0;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<1000000;i++){
        if(a[i]>='0'&&a[i]<='9'){
            b[ans]=a[i]-'0';
            ans++;
        }
    }
    if(ans==0) cout<<0;
    if(ans==1) cout<<b[1];
    else{

        sort(b,b+ans,cmp);
        for(int i=0;i<ans;i++){
            cout<<b[i];
        }
    }
    return 0;
}
