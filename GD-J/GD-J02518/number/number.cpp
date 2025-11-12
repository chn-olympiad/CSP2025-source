#include<bits/stdc++.h>
using namespace std;
char a[1001];
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int sum=0;
    sum=s.length();
    for(int i=0;i<=sum;i++){
        if(s[i]>'0'&&s[i]<='9'){
            a[i]=s[i];
            a[i]-=48;
        }else if(s[i]=='0'){
            a[i]='0'-1;
        }
    }
    for(int i=1;i<=sum-1;i++){
        for(int j=1;j<=sum-1;j++){
            if(a[j]<a[j+1]&&a[j]!=10){
                swap(a[j],a[j+1]);
            }
        }
    }
    for(int k=sum;k>=0;k--){
        if(a[k]>0&&a[k]<=9){
            cout<<a[k];
        }else if(a[k]=='0'-1) cout<<0;
    }
    return 0;
}

