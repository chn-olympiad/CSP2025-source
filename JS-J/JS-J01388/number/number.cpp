#include<bits/stdc++.h>
using namespace std;
string s;
int a[100000005],cnt,k;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[cnt]=s[i]-'0';
            cnt++;
        }
    }
    for(int i=0;i<cnt-1;i++){
        for(int j=i+1;j<cnt;j++){
            if(a[i]<a[j]){
                k=a[i];
                a[i]=a[j];
                a[j]=k;
            }
        }
    }
    for(int i=0;i<cnt;i++){
        cout<<a[i];
    }
    return 0;
}
