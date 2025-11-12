#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50;
int a[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=s.size();
    for(int i=1;i<=n;i++){
        if(s[i-1]>='0'&&s[i-1]<='9'){
            a[i]=s[i-1]-'0';
        }
        else{
            a[i]=-1;
        }
    }
    sort(a+1,a+1+n);
    for(int i=n;i>=1;i--){
        if(a[i]==-1){
            break;
        }
        cout<<a[i];
    }
    cout<<'\n';
    return 0;
}
