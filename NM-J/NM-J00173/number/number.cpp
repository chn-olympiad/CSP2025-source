#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
    int cnt=0;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >>s;
    for(int i=0;i<=s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[i]=s[i]-'0';
            cnt++;
        }
    }
    for(int i=cnt;i>=0;i--){
        for(int j=0;j<i;j++){
        if (a[j]<a[j+1]){
            int f=a[j+1];
            a[j+1]=a[j];
            a[j]=f;
        }
    }
    }
    for(int i=0;i<cnt;i++){
        cout<<a[i];
    }
    fclose("number.in");
    fclose("number.out");
    return 0;
}
