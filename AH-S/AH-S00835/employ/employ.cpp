#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,a[100005],f=0,c=0,num=0;
    string s;
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(n<=10){
        if(n==1){
            if(s=="0"){
                cout<<"0";
            }else{
                cout<<"1";
            }
        }
        return 0;
    }
    if(m==1&&n>=500){
        int eee=0,mm=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                eee=i+1;
                break;
            }
        }
        if(eee<a[n+1]){
            cout<<0;
        }else{
            for(int i=eee;i<=a[n+1];i++){
                if(s[i]=='1'){
                    mm++;
                }
            }
            cout<<mm;
        }
        return 0;
    }
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            f=1;
        }
        if(s[i]=='1'){
            num++;
        }else{
            c++;
            for(int j=i+1;j<=n;j++){
                if(c>a[i]){
                    c++;
                }
            }
        }
    }
    if(n>100&&m==n){
        if(f==1){
            cout<<0;
            return 0;
        }
        cout<<n;
        return 0;
    }
    cout<<num;
    return 0;
}
