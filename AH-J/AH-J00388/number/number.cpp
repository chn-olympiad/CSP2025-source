#include<bits/stdc++.h>
using namespace std;
string s,b;
int a[66];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int i,j;
    for(i=0;i<s.size();i++){
        if(isdigit(s[i])==true){
            int t=s[i];
            a[t]++;
        }
    }
    int n=0;
    for(i=48;i<=58;i++){
        if(a[i]!=0){
            for(j=1;j<=a[i];j++){
                b[n]=i;
                n++;
            }
        }
    }
    bool r=false;
    for(i=n-1;i>=0;i--){
        if(b[i]=='0'&&r==false&&i!=0){
            continue;
        }else{
            r=true;
            cout<<b[i];
        }

    }
    return 0;
}
